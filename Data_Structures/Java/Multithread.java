public class P10 
{
    public static void main(String []sk ) 
{
     	     Runnable r = new Runnable1();
    	     Thread t = new Thread(r);
   	      t.start();
    	     Runnable r2 = new Runnable2();
   	     Thread t2 = new Thread(r2);
    	     t2.start();
            }
}

class Runnable2 implements Runnable
{
        public void run()
      {
        for(int i=0;i<21;i++)
         {
                if(i%2 == 1)
                    System.out.println(i);
          }
     }
}
