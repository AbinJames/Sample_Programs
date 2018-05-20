import java.io.*;
import java.net.*;
import java.lang.*;
public class UDPclient
{
	public static void main(String args[])throws Exception
	{
		try
		{
				MulticastSocket ms = new MulticastSocket(16700);
				InetAddress dest = InetAddress.getByName("239.0.1.2");
				byte[] line = new byte[100];
				System.out.println("Enter text to send");
			    do
				{
					int len = System.in.read(line);
					DatagramPacket pkt = new DatagramPacket(line,len,dest,16700);
					ms.send(pkt);
				}while(true);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}

		}
}