#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFF_LEN 1000
#define PORT_NUM 1000

int showAddr(struct sockaddr *addr, socklen_t len)
{
    if (addr == NULL)
    {
	printf("showAddr: NULL addr pointer!\n");
	return -1;
    }
    if (len <= 2)
    {
	printf("showAddr: invalid len!\n");
	return -1;
    }

    switch (addr->sa_family)
    {
	case AF_INET:
	    printf("Socket addr: len=%d AF_INET %s:%d\n", len,
		   inet_ntoa(((struct sockaddr_in *) addr)->sin_addr),
		   ntohs(((struct sockaddr_in *) addr)->sin_port));
	    break;
	default:
	    printf("unrecognized address family!\n");
    }
    return 0;
}

int showSockAddr(int sock)
{
    int ret = 0;
    struct sockaddr addr = { };
    socklen_t len = sizeof(struct sockaddr);

    errno = 0;
    if ((ret = getsockname(sock, &addr, &len)) < 0)
    {
	printf("get socket name failed! ret=%d errno=%d\n", ret, errno);
	return ret;
    }
    ret = showAddr(&addr, len);
    return ret;
}

void dump_buff(unsigned char *buf, int len)
{
    int i = 0;
    for (; i < len; i++)
    {
	printf((i + 1) % 16 ? "0x%02x " : "0x%02x\n", buf[i]);
    }
    printf("\n");
}

void dump_icmp_unrch(unsigned char *buf, int len)
{
    if (len < 36)
	return;
    char *buff;
    buff = (buf[1] == 1) ? " host " : ((buf[1] == 3) ? " port " : " ");
    printf("address %d.%d.%d.%d:%d %s unreachable\n", buf[24], buf[25],
	   buf[26], buf[27], buf[31] + (buf[30] << 8), buff);
}

void dump_icmp(unsigned char *buf, int len)
{
    if (len < 24)
	return;
    printf("icmp type %d code %d\n", buf[20], buf[21]);
    if (buf[20] == 3)
    {
	dump_icmp_unrch(&buf[20], len - 20);
    }
    else
    {
	return;
    }
}


int main(int argc, char **argv)
{
    int sock, icmp_sock;
    int len, port;
    unsigned char buf[BUFF_LEN];
    struct sockaddr_in addr_dst, addr_src;

    if (argc < 2)
    {
	printf("usage: %s dst_host\n", argv[0]);
	return -1;
    }

    addr_dst.sin_family = AF_INET;
    addr_dst.sin_addr.s_addr = inet_addr(argv[1]);
    addr_src.sin_family = AF_INET;
    addr_src.sin_port = htons(5678);
    addr_src.sin_addr.s_addr = inet_addr("172.16.121.204");

    icmp_sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (icmp_sock == -1)
    {
	printf("Can't creat socket:icmp raw!\n");
	return -1;
    }
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
    {
	printf("Can't creat socket:udp!\n");
	return -1;
    }

    errno = 0;
    if (bind
	(sock, (struct sockaddr *) &addr_src, sizeof(struct sockaddr_in)) < 0)
    {
	printf("Bind failed!errno=%d\n", errno);
	return -1;
    }
    //showSockAddr(sock);

    fd_set set;
    FD_ZERO(&set);
    FD_SET(icmp_sock, &set);

    for (port = 1; port < PORT_NUM; port++)
    {
	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 3000000;
	int ret = 0;
	//printf("start sending %s:%d:\n", argv[1], port);
	addr_dst.sin_port = htons(port);
	errno = 0;
	len = sendto(sock, buf, BUFF_LEN, 0, (struct sockaddr *) &addr_dst,
		     sizeof(struct sockaddr_in));
	if (len < BUFF_LEN)
	{
	    printf("Send failed!%d bytessended errno=%d\n", len, errno);
	    return -1;
	}
	else
	{
	    // printf("%d bytes sended to:\n", len);
	    //showAddr((struct sockaddr*)&addr_dst, sizeof(struct sockaddr_in));
	}
	errno = 0;

	ret = select(icmp_sock + 1, &set, NULL, NULL, &timeout);
	if (ret == -1)
	{
	    printf("select failed!errno=%d!\n", errno);
	    return -1;
	}
	else if (ret)
	{
	    //printf("select ret %d is icmp recved %d\n", ret, FD_ISSET(icmp_sock, &set));
	    while ((len = recv(icmp_sock, buf, BUFF_LEN, MSG_DONTWAIT)) > 0)
	    {
		printf("icmp  recved:\n");
		dump_icmp(buf, len);
	    }
	}
	else
	{
	    printf("select timeout!\n");
	    showAddr((struct sockaddr *) &addr_dst,
		     sizeof(struct sockaddr_in));
	    FD_SET(icmp_sock, &set);
	}

    }
    return 0;
}
