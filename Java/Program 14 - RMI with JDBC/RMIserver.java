import java.rmi.*;
import java.rmi.server.*;
import java.sql.*;
import java.util.*;
public class RMIserver extends UnicastRemoteObject implements RMIinterface
{
	


	public RMIserver () throws RemoteException 
	{
		super();

	}
	public List<String> sel(String query,int c) throws RemoteException
	{
		List<String> list = new ArrayList<String>();
		List<String> alt =new ArrayList<String>();

		alt.add("");
		try
		{
			String url="jdbc:mysql://localhost/data";
			String uname="root";
			String pass="";
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection(url,uname,pass);
			Statement st = con.createStatement();
			ResultSet rs=st.executeQuery(query);
					String userData="";
					while(rs.next())
					{
						for(int i=1;i<=c;i++)
							userData=userData+rs.getString(i)+" ";
						list.add(userData);
						userData="";
					}
					return list;

        }
			
		
		catch(Exception e)
		{
			System.out.println(e);
			return alt;
		}	
	}
	public void exec(String query) throws RemoteException
	{
		try
		{
			String url="jdbc:mysql://localhost/Data";
			String uname="root";
			String pass="";
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection(url,uname,pass);
			Statement st = con.createStatement();
			st.execute(query);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
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