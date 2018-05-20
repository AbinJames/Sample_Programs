import java.io.*;
import java.net.*;
import java.lang.*;

public class TCPServer implements Runnable
{
	ServerSocket ss;
	static int i=0, n=2;
	Socket[] s = new Socket[n];
	BufferedReader[] br = new BufferedReader[n];
	String str;
	PrintWriter[] pr = new PrintWriter[n];
	Thread t1=null,t2=null;
	public TCPServer()
	{
		try
		{
			ss = new ServerSocket(3000);
			System.out.println("Server is waiting");
			while(i<n)
			{
				s[i] = ss.accept();
				br[i] = new BufferedReader(new InputStreamReader(s[i].getInputStream()));
				pr[i] = new PrintWriter (new OutputStreamWriter(s[i].getOutputStream()),true);
				System.out.println("Connected with client "+(i+1));
				i++;
			}
		}
		catch (Exception e)
		{
			System.out.println("Connection closed with "+e);
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
					str=br[0].readLine();
					pr[1].println(str);
				}
				else
				{
					str=br[1].readLine();
					pr[0].println(str);
				}
			}while(!str.equals("exit"));
		}
		catch (Exception e)
		{
			System.out.println(e);
		}
	}
	public static void main (String args[]) throws Exception
	{
		TCPServer s = new TCPServer();
		
		s.t1=new Thread(s);
		s.t1.start();
		s.t2=new Thread(s);
		s.t2.start();
		
	}
}
