class Base
{
    private static int a = 1;
    protected static int b = 2;
    public int getA()
    {
        return a;
    }
    public void setA(int c)
    {
        a =  c;
    }
    public int getB()
    {
        return b;
    }
    public void setB(int c)
    {
        b = c;
    }
}

public class Child extends Base
{
    public static void main(String[] args)
    {
        Base a = new Base();
        Child b = new Child();
        System.out.println("a.a" + a.getA());
        System.out.println("set a to 3");
        a.setA(3);
        System.out.println("b.a" + b.getA());
    }
}
