import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import java.net.*;
import java.lang.*;
interface X extends ActionListener{}
interface Y extends Runnable{}
public class FrameClient implements X,Y
{
	Frame f;
	Panel p1,p2;
	String msg;
	TextArea t,te2; 
	Label l;
	Button send;
	Socket s;
	BufferedReader br1,br2;
	String str;
	PrintWriter pr;
	Thread t1=null,t2=null;

	public FrameClient() 
	{
		try
		{
			s = new Socket("localhost",3000);
			br1 = new BufferedReader(new InputStreamReader(System.in));
			br2 = new BufferedReader(new InputStreamReader(s.getInputStream()));
			pr = new PrintWriter (new OutputStreamWriter(s.getOutputStream()),true);
			System.out.println("Connected with server");
		}
		catch (Exception e)
		{
			System.out.println("Connection closed in client with "+e);
		}
		f=new Frame();
		t = new TextArea(75,50);
		te2 = new TextArea(75,50);
		te2.setEditable(false);
		f.setSize(400,400);
		f.setLayout(new GridLayout(4,1));
		l=new Label("Messages");
		p2 = new Panel();
		send = new Button("Send");
		f.add(l);
		f.add(te2);
		f.add(t);
		f.add(p2);			
		
		p2.add(send);
		send.addActionListener(this);
		f.addWindowListener(
			new WindowAdapter()
			{
				public void windowClosing(WindowEvent we){
					f.dispose();
					System.exit(0);
				}
			});
		f.setVisible(true);
	}
	public void actionPerformed(ActionEvent ae) 
	{
		if(ae.getActionCommand().equals("Send"))
		{
			msg = t.getText();
			t.setText("");
			te2.setText(te2.getText()+"\nYou : " +msg);
			pr.println(msg);
		}
		
	}
	public void run()
	{
		try
		{
			do
			{
				if(Thread.currentThread()==t1)
				{
					
					msg=br2.readLine();
					te2.setText(te2.getText()+"\nClient " +msg);
				}
			}while(!msg.equals("exit"));
		}
		catch (Exception e)
		{
			System.out.println("Closed in client with "+e);
		}
	}

	public static void main (String args[]) throws Exception
	{
		FrameClient c = new FrameClient();
		c.t1=new Thread(c);
		c.t1.start();
			
	}
}
