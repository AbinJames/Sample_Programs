import java.rmi.*;
public interface RMIinterface extends Remote
{
	public int add(int a,int b) throws RemoteException;
}
