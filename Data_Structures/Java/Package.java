//Base Package class:
package p1;
public class A
{
	int a=1;
	public int b=2;
	protected int c=3;
	private int d=4;
	public A()
	{
		System.out.println("Base Constructor");
		System.out.println("A="+a);
		System.out.println("B="+b);
		System.out.println("c="+c);
		System.out.println("D="+d);
	}	
}
Same Package subclass:
package p1;
public class B extends A
{
	public static void main(String[] args) 
	{
		A obj=new A();
		System.out.println("Same Package");
		System.out.println("A="+obj.a);
		System.out.println("B="+obj.b);
		System.out.println("c="+obj.c);
	}
}
Same Package non-subclass:
package p1;
public class B 
{
	public static void main(String[] args) 
	{
		A obj=new A();
		System.out.println("Same Package");
		System.out.println("A="+obj.a);
		System.out.println("B="+obj.b);
		System.out.println("c="+obj.c);
	}
}

//Different Package subclass:
package p2;
public class B extends p1.Package
{
	B()
	{
		System.out.println("Different Package and subclass");
		System.out.println("B="+b);
		System.out.println("c="+c);
	}
}
Main Class:
//package p2;
class C
{
	public static void main(String[] args) 
	{
		B obj=new B();
	}
}
//Different Package non-subclass:
package p2;
public class B 
{
	B()
	{
		p1.A x=new p1.A(); 
		System.out.println("Different Package and non-subclass");
		System.out.println("B="+x.b);
	}
}
//Main Class:
package p2;
class C
{
	public static void main(String[] args) 
	{
		B obj=new B();
	}
}
