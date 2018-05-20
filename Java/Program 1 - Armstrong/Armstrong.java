import java.io.*;
//import java.util.*
public class Armstrong
{
	public static  void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));      //Scanner in =new Scanner(System.in);
		System.out.println("Enter number");
		int n = Integer.parseInt(br.readLine());        //int n=in.nextInt();
		int a,temp=n,num=0; 
		while(n!=0)
		{
			a=n%10;
			n=n/10;
			num+=(a*a*a);
			
		}
		if(num==temp)
			System.out.println("Number is armstrong");
		else
			System.out.println("Number is not armstrong");
	}
}