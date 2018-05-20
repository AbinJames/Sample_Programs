import java.io.*;
import java.net.*;

public class TCPServer
{
	public static void main (String args[]) throws Exception
	{
		ServerSocket ss = new ServerSocket(6000);
		String str;
		System.out.println("Server is listening and waiting for client");
		Socket s = ss.accept();
		BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
		try
		{
		while(true)
		{
		str=br.readLine();
		if(str.equals("quit"))
			break;
		System.out.println("Client says : "+str);
		}
		}
		catch (Exception e)
		{
			System.out.println("Connection closed");
		}
		
	}
}
