#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

#define BUFF_LEN 300
#define PORT_NUM 65536

struct sock_extended_err
{
    u_int32_t ee_errno;		/* error number */
    u_int8_t ee_origin;		/* where the error originated */
    u_int8_t ee_type;		/* type */
    u_int8_t ee_code;		/* code */
    u_int8_t ee_pad;
    u_int32_t ee_info;		/* additional information */
    u_int32_t ee_data;		/* other data */
    /* More data may follow */
};
#define SO_EE_OFFENDER(ee)  ((struct sockaddr*)((ee)+1))

void inline error_print(char *msg)
{
    printf("%s!errno=%d, %s\n", msg, errno, strerror(errno));
    return;
}

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
	    printf("unrecognized address family! %d\n", addr->sa_family);
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
	error_print("get socket name failed!");
	errno = 0;
	return ret;
    }
    ret = showAddr(&addr, len);
    return ret;
}

int recv_err(int sock)
{
    char buf[BUFF_LEN];
    char cbuf[BUFF_LEN];
    struct msghdr msghdr = { };
    struct cmsghdr *cmsghdr = NULL;
    struct sock_extended_err *icmp = NULL;
    struct iovec iovec;
    struct sockaddr *icmp_src;
    iovec.iov_base = buf;
    iovec.iov_len = BUFF_LEN;
    msghdr.msg_iov = &iovec;
    msghdr.msg_iovlen = 1;
    msghdr.msg_control = &cbuf;
    msghdr.msg_controllen = BUFF_LEN;

    if (recvmsg(sock, &msghdr, MSG_ERRQUEUE) > 0)
    {
	cmsghdr = (struct cmsghdr *) msghdr.msg_control;
	printf("cmsglen=%d level=%d type=%d\n",
	       cmsghdr->cmsg_len, cmsghdr->cmsg_level, cmsghdr->cmsg_type);
	icmp = (struct sock_extended_err *) CMSG_DATA(cmsghdr);
	if (icmp == NULL)
	{
	    printf("err package error!\n");
	    return -1;
	}
	printf("send failed error pack: %d type: %d code: %d\n",
	       icmp->ee_origin, icmp->ee_type, icmp->ee_code);
	icmp_src = SO_EE_OFFENDER(icmp);
	showAddr((struct sockaddr *) &icmp_src, sizeof(struct sockaddr));
	return 0;
    }
    return -1;
}


int main(int argc, char **argv)
{
    int sock;
    int len, port;
    char buf[BUFF_LEN];
    struct sockaddr_in addr_dst, addr_src, *src;
    int err_opt = 1;

    if (argc < 2)
    {
	printf("usage: %s dst_host\n");
	return -1;
    }

    addr_dst.sin_family = AF_INET;
    addr_dst.sin_addr.s_addr = inet_addr(argv[1]);
    addr_src.sin_family = AF_INET;
    addr_src.sin_port = htons(5678);
    addr_src.sin_addr.s_addr = inet_addr("172.16.121.204");

    errno = 0;
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
    {
	error_print("Can't creat udp socket!");
	return -1;
    }

    if (bind
	(sock, (struct sockaddr *) &addr_src, sizeof(struct sockaddr_in)) < 0)
    {
	error_print("Bind failed!");
	return -1;
    }

    printf("Bind at:\n\t");
    showSockAddr(sock);

    if (setsockopt(sock, IPPROTO_IP, IP_RECVERR, &err_opt, sizeof(int)))
    {
	error_print("Set sockopt failed!");
	return -1;
    }

    for (port = 1024; port < PORT_NUM; port++)
    {
	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 500000;
	int ret = 0;
	//printf("start sending %s:%d:\n", argv[1], port);
	addr_dst.sin_port = htons(port);
	errno = 0;
      send:
	len = sendto(sock, buf, BUFF_LEN, 0, (struct sockaddr *) &addr_dst,
		     sizeof(struct sockaddr_in));
	if (len < BUFF_LEN)
	{
	    error_print("Send failed");
	    printf("%d bytes sended\n", len);
	    if (recv_err(sock) == 0)
	    {
		goto send;
	    }
	    return -1;
	}
	printf("packet sended to: ");
	showAddr((struct sockaddr *) &addr_dst, sizeof(struct sockaddr_in));
    }
    return 0;
}
