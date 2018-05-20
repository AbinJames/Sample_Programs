import java.rmi.*;
import java.io.*;
public class RMIclient
{
	public static void main(String args[])
	{
		BufferedReader br1,br2;
		String str1,str2;
		try
		{
			RMIinterface rmi2  = (RMIinterface)Naming.lookup("MYNAME");
			try
			{
				br1 = new BufferedReader(new InputStreamReader(System.in));
				System.out.println("Enter 1st no");
				str1 = br1.readLine();
				int a = Integer.parseInt(str1);
				System.out.println("Enter 2nd no");
				str1 = br1.readLine();
				int b = Integer.parseInt(str1);
				System.out.println("Server sum : "+rmi2.add(a,b));

			}
			catch(Exception e)
			{
				System.out.println(e);
			}
		} 
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}