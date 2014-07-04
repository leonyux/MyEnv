struct a
{
    int a;
    int b;
};

int main(int argc, char **argv)
{
    struct a *b;
    struct a c;
    b = &c;
    b->b = 1;
    int *d = &c.b;
    *d = 2;
    return 0;
}
