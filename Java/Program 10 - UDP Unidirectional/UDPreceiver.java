import java.io.*;
import java.net.*;
import java.lang.*;
public class UDPreceiver
{
	public static void main(String args[])throws Exception
	{
		while(true)
			{
				try
				{
					DatagramSocket ds = new DatagramSocket(15000);
					byte[] buffer = new byte[350];
					DatagramPacket dp = new DatagramPacket (buffer,buffer.length);
 					ds.receive(dp);
 					System.out.println(new String(dp.getData(),0,dp.getLength()));
				}
				catch(Exception e)
				{
					
				}
			}
	}
}