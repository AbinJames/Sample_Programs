import java.io.*;
import java.net.*;
import java.lang.*;

public class TCPServer implements Runnable
{
	ServerSocket ss;
	Socket s;
	BufferedReader br1,br2;
	String str;
	PrintWriter pr;
	Thread t1=null,t2=null;
	public TCPServer()
	{
		try
		{
			ss = new ServerSocket(3000);
			System.out.println("Server is waiting");
			s = ss.accept();
			System.out.println("Connected with client");
			br1 = new BufferedReader(new InputStreamReader(System.in));
			br2 = new BufferedReader(new InputStreamReader(s.getInputStream()));
			pr = new PrintWriter (new OutputStreamWriter(s.getOutputStream()),true);
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
					str=br1.readLine();
					pr.println(str);
				}
				else
				{
					str=br2.readLine();
					System.out.println("Client says : "+str);
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
		s.t2=new Thread(s);
		s.t1.start();
		s.t2.start();	
	}
}
