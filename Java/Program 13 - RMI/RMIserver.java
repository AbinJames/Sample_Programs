import java.rmi.*;
import java.rmi.server.*;
public class RMIserver extends UnicastRemoteObject implements RMIinterface
{
	public RMIserver () throws RemoteException 
	{
		super();
	}
	public int add(int a, int b) throws RemoteException
	{
		return a+b;
	}
	public static void main(String args[])
	{
		try 
		{
			RMIinterface rmi1 = new RMIserver();
			Naming.rebind("MYNAME",rmi1);
			System.out.println("Object is registered");
			System.out.println("Server is waiting");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
} 