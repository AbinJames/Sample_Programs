import java.rmi.*;
import java.sql.*;
import java.util.*;
public interface RMIinterface extends Remote
{
	public List<String> sel(String query,int c) throws RemoteException;
	public void exec(String query) throws RemoteException;
}
