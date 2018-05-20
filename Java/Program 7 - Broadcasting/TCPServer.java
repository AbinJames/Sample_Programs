import java.io.*;
import java.net.*;
import java.lang.*;

public class TCPServer implements Runnable
{
	ServerSocket ss;
	Socket[] s = new Socket[3];
	BufferedReader[] br = new BufferedReader[3];
	BufferedReader br1= new BufferedReader(new InputStreamReader(System.in));
	String str,str2;
	PrintWriter[] pr = new PrintWriter[3];
	int i=0,j=0;
	Thread t1=null;
	Thread t[] = new Thread[3];
	public TCPServer()
	{
		try
		{
			ss = new ServerSocket(3000);
			System.out.println("Server is waiting");
			while(true)
{
			s[i] = ss.accept();
			System.out.println("Connected with client");
			br[i] = new BufferedReader(new InputStreamReader(s[i].getInputStream()));
			pr[i] = new PrintWriter (new OutputStreamWriter(s[i].getOutputStream()),true);
			t[j] = new Thread(this);
			t[j].start();
			j++;
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
				if(Thread.currentThread()==t[0])
				{
					str=br1.readLine();
					for(int x = 0;x<2;x++)
						pr[x].println("Server says : "+str);

				}
				else
				{
					str=br[0].readLine();
					pr[1].println("Client says : "+str);
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
		
	}
}
