import java.io.*;
import java.net.*;
import java.lang.*;
public class UDPsender
{
	public static void main(String args[])throws Exception
	{
		while(true)
			{
				try
				{
					BufferedReader in= new BufferedReader(new InputStreamReader(System.in));
					String str = in.readLine();
					byte[] buffer = str.getBytes();
					DatagramSocket ds = new DatagramSocket();
					DatagramPacket dp = new DatagramPacket (buffer,buffer.length,InetAddress.getByName("localhost"),15000);
 					ds.send(dp);
				}
				catch(Exception e)
				{
					System.out.println(e);
					break;
				}
			}
	}
}