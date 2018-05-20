import java.io.*;
import java.net.*;
import java.lang.*;

public class TCPClient implements Runnable
{
	Socket s;
	BufferedReader br1,br2;
	String str;
	PrintWriter pr;
	Thread t1=null,t2=null,t3=null;
	public TCPClient()
	{
		try
		{
			s = new Socket("localhost",3000);
			br1 = new BufferedReader(new InputStreamReader(System.in));
			br2 = new BufferedReader(new InputStreamReader(s.getInputStream()));
			pr = new PrintWriter (new OutputStreamWriter(s.getOutputStream()),true);
		System.out.println("Connected with server");
}
		catch (Exception e)
		{
			System.out.println("Connection closed in client with "+e);
		}
	}
	public void run()
	{
		try
		{
			do
			{
				if(Thread.currentThread()==t1)
				{
					str=br1.readLine();
					pr.println(str);
				}
				else
				{
					str=br2.readLine();
					System.out.println(str);
				}
			}while(!str.equals("exit"));
		}
		catch (Exception e)
		{
			System.out.println("Closed in client with "+e);
		}
	}
	public static void main (String args[]) throws Exception
	{
		TCPClient c = new TCPClient();
		c.t1=new Thread(c);
		c.t2=new Thread(c);
		c.t3=new Thread(c);
		c.t1.start();
		c.t2.start();
		c.t3.start();
			
	}
}
