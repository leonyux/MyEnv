#include <stdio.h>

void func1(void)
{
    printf("in func1");
}

void func2(void)
{
  label2:
    printf("a");
    goto label2;
}

int main(int argc, char **argv)
{
    func2();
    return (0);
}
