#include <stdio.h>
#pragma pack(push, 1)
struct A
{
    int a;
    int b;
    char c;
    char d;
    int e;
    struct
    {
	char a;
	int b;
	char c;
    } f;
    char g;
    int h;
};
#pragma pack(pop)

int main(int argc, char **argv)
{
    struct A *p = (struct A *) 0;
    printf("&A.a=0x%x\n", (unsigned int) &p->a);
    printf("&A.b=0x%x\n", (unsigned int) &p->b);
    printf("&A.c=0x%x\n", (unsigned int) &p->c);
    printf("&A.d=0x%x\n", (unsigned int) &p->d);
    printf("&A.e=0x%x\n", (unsigned int) &p->e);
    printf("&A.f=0x%x\n", (unsigned int) &p->f);
    printf("&A.f.a=0x%x\n", (unsigned int) &p->f.a);
    printf("&A.f.b=0x%x\n", (unsigned int) &p->f.b);
    printf("&A.f.c=0x%x\n", (unsigned int) &p->f.c);
    printf("&A.g=0x%x\n", (unsigned int) &p->g);
    printf("&A.h=0x%x\n", (unsigned int) &p->h);

    return (0);
}
