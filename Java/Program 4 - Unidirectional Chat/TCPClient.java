import java.io.*;
import java.net.*;

public class TCPClient
{
	public static void main (String args[]) throws Exception
	{
		Socket s = new Socket("localhost",6000);
		String str;
		System.out.println("Client is running");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try
		{
		
		while(true)
		{
			System.out.println("Client says");
			str=br.readLine();
			if(str.equals("quit"))
				break;
			PrintWriter pr = new PrintWriter (new OutputStreamWriter(s.getOutputStream()),true);
			pr.println(str);
			System.out.println("Data sent");
		}
		}
		catch (Exception e)
		{
		}
		
	}
}
