class NegativeIntegerException extends Exception
{
int i;
NegativeIntegerException(int x)
	{
	i=x;
	}
public  String toString()
	{
	return "You have entered negative value:"+i;
	}
}
class P9
{
	public static void main(String [] sk)
	{
		int x=Integer.parseInt(sk[0]);
		
		
		try
		{
			
			if(x<0)
			{
				throw new NegativeIntegerException(x);
			}
			else
			{
				System.out.print("Thank You !!!!");
			}
		}
		catch(NegativeIntegerException ne)
		{
			System.out.println(ne);
		}
	}
}
