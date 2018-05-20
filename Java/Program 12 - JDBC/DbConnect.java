
import java.sql.*;
import java.util.*;
import java.io.*;

public class DbConnect {
	public static void main(String args[]) throws Exception
	{
		String url="jdbc:mysql://localhost/Data";
		String uname="root";
		Scanner s=new Scanner(System.in);
		String query="",name;
		String pass="";
		int i,c=0,rollno,flag,marks,op;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Class.forName("com.mysql.jdbc.Driver");
		try
		{
			Connection con = DriverManager.getConnection(url,uname,pass);
			do
			{
				System.out.println("Please select option\n1. Select\n2. Insert\n3. Update\n4. Delete\n5. Exit\n");
				op=Integer.parseInt(br.readLine());
				flag=0;
				switch(op)
				{
					case 1:
					flag=1;
					System.out.println("Please select option\n1. rollno\n2. name\n3. marks\n4. all");
					i=Integer.parseInt(br.readLine());
					switch(i)
					{
						case 1:
						query="select rollno from student";
						c = 1;
						break;
						case 2:
						query="select name from student";
						c =1;
						break;
						case 3:
						query="select marks from student";
						c =1;
						break;
						case 4:
						query="select * from student";
						c = 3;
						break;
					}
					break;
					case 2:
					System.out.println("Enter rollno");
					rollno=Integer.parseInt(br.readLine());
					System.out.println("Enter name");
					name=br.readLine();
					System.out.println("Enter marks");
					marks=Integer.parseInt(br.readLine());
					query = "INSERT INTO `student`(`rollno`, `name`, `marks`) VALUES ("+rollno+",'"+name+"',"+marks+");";
					c=0;
					break;
					case 3:
					System.out.println("Please select option\n1. name\n2. marks");
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
					break;
					case 4:
					System.out.println("Enter rollno to delete");
					rollno = Integer.parseInt(br.readLine());
					c=0;
					query = "delete from student where rollno = "+rollno;
					break;


				}
				Statement st = con.createStatement();

				if(flag==1)
				{
					System.out.println("Result:");
					ResultSet rs=st.executeQuery(query);
					String userData="";
					while(rs.next())
					{
						for(i=1;i<=c;i++)
							userData=userData+rs.getString(i)+" ";
						System.out.println(userData);
						userData="";
					}
				}
				else
					st.execute(query);
			}while(op!=5);

		}
		catch(Exception e) 
		{
			System.out.println(e);
		}

	}

}
