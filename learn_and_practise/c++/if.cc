#include <stdio.h>
#define MACB

int main(int argc, char** argv)
{

#if defined(MACA) || defined(MACB)
    printf("haha\n");
#endif
    printf("hoho\n");
    return 0;
}

