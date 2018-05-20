				import java.util.*;
				import java.io.*;
import java.net.*;
import java.lang.*;

public class TCPServer implements Runnable
{
	ServerSocket ss;
	Socket[] s = new Socket[10];
	BufferedReader[] br = new BufferedReader[10];
	String str,str2;
	PrintWriter[] pr = new PrintWriter[10];
	int i=0;
	Thread[] t = new Thread[10]; 
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
				t[i] = new Thread(this);
				t[i].start();
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
			while(true)
			{
				for(int num = 0;num<i;num++)
				{
					if(Thread.currentThread()==t[num])
					{
						str = br[num].readLine();
						if(str.equals("exit"))
							break;
						for(int num2 = 0;num2<i;num2++)
						{
							int client = num+1;
							if(num2!=num)
								pr[num2].println(client+" says : "+str);
						}
					}
				}
				if(str.equals("exit"))
							break;
			}
		}
		catch (Exception e)
		{
			System.out.println(e);
		}
	}
	public static void main(String args[])
	{
		TCPServer s = new TCPServer();

	}
}