import java.rmi.*;
import java.io.*;
import java.sql.*;
import java.util.*;
public class RMIclient
{
	public static void main(String args[])
	{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		String query="",name;
		int i,c=0,rollno,marks,op;
		try
		{
			RMIinterface rmi2  = (RMIinterface)Naming.lookup("MYNAME");
			try
			{
				do
				{
				System.out.println("\nPlease select option\n1. Select\n2. Insert\n3. Update\n4. Delete\n5. Exit");
				op=Integer.parseInt(br.readLine());
				switch(op)
				{
					case 1:
					System.out.println("\nPlease select option\n1. rollno\n2. name\n3. marks\n4. all");
					i=Integer.parseInt(br.readLine());
					switch(i)
					{
						case 1:
						query="select rollno from student order by rollno";
						c = 1;
						break;
						case 2:
						query="select name from student order by rollno";
						c =1;
						break;
						case 3:
						query="select marks from student order by rollno";
						c =1;
						break;
						case 4:
						query="select * from student order by rollno";
						c = 3;
						break;
					}
					
					List<String> list = rmi2.sel(query,c);
					
					for(String outp : list) 
            			System.out.println(outp);
        
					break;
					case 2:
					System.out.println("\nEnter rollno");
					rollno=Integer.parseInt(br.readLine());
					System.out.println("Enter name");
					name=br.readLine();
					System.out.println("Enter marks");
					marks=Integer.parseInt(br.readLine());
					query = "INSERT INTO `student`(`rollno`, `name`, `marks`) VALUES ("+rollno+",'"+name+"',"+marks+");";
					c=0;
					rmi2.exec(query);
					break;
					case 3:
					System.out.println("\nPlease select option\n1. name\n2. marks");
					i=Integer.parseInt(br.readLine());
					System.out.println("Enter rollno to update");
					rollno = Integer.parseInt(br.readLine());
					System.out.println("Enter update value");
					name = br.readLine();
					c=0;
					switch(i)
					{
						case 1:
						query="update student set name = '"+ name +"'";

						break;
						case 2:
						query="update student set marks = "+name;
						break;
					}
					query = query+" where rollno = "+rollno;
					rmi2.exec(query);
					break;
					case 4:
					System.out.println("\nEnter rollno to delete");
					rollno = Integer.parseInt(br.readLine());
					c=0;
					query = "delete from student where rollno = "+rollno;
					rmi2.exec(query);
					break;


				}

			}while(op!=5);
				

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