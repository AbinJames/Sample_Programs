import java.io.*;
import java.net.*;
import java.lang.*;
public class UDPserver
{
	public static void main(String args[])throws Exception
	{
		try
		{
				MulticastSocket ms = new MulticastSocket(16700);
				InetAddress dest = InetAddress.getByName("239.0.1.2");
				String msg;
				ms.joinGroup(dest);
			    do
				{
					byte[] line = new byte[100];
					DatagramPacket pkt = new DatagramPacket(line,line.length);
					ms.receive(pkt);
					msg = new String(pkt.getData());
					System.out.println("From "+pkt.getAddress() + " : "+msg.trim());
				
				}while(!msg.trim().equals("close"));
				ms.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}

		}
}