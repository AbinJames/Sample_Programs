import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.util.*;

public class FrameCalculator implements ActionListener{
	int x,de,n,m;
	double a,b,c,y;
	Frame f;
	Panel p1,p2,p3;
	String op;
	Label l,l2;
	Button add,sub,div,mul,eq,ce,ca,d;
	Button[] num = new Button[10];

	public FrameCalculator() 
	{
		de=0;n=1;m=10;
		f=new Frame();
		f.setSize(200,300);
		f.setLayout(new GridLayout(3,1));
		l=new Label("                   ");
		l2=new Label("                  ");
		p1= new Panel();
		f.add(p1);
		p1.setLayout(new GridLayout(2,1));				
		p1.add(l);
		p1.add(l2);

		p2= new Panel();
		f.add(p2);
		p2.setLayout(new GridLayout(1,2));
		p3= new Panel();
		f.add(p3);
		p3.setLayout(new GridLayout(4,4));
		for(int i=0;i<10;i++)
			num[i] = new Button(Integer.toString(i));
		add = new Button("+");
		sub = new Button("-");
		mul = new Button("*");
		div = new Button("/");
		eq = new Button("=");
		ce = new Button("C");
		ca = new Button("CA");
		d = new Button(".");
		p2.add(ce);
		p2.add(ca);
		p3.add(num[7]);
		p3.add(num[8]);
		p3.add(num[9]);
		p3.add(add);
		p3.add(num[6]);
		p3.add(num[5]);
		p3.add(num[4]);
		p3.add(sub);
		p3.add(num[3]);
		p3.add(num[2]);
		p3.add(num[1]);
		p3.add(mul);
		p3.add(d);
		p3.add(num[0]);
		p3.add(eq);
		p3.add(div);
		for(int i=0;i<10;i++)
			num[i].addActionListener(this);
		d.addActionListener(this);
		add.addActionListener(this);
		sub.addActionListener(this);
		mul.addActionListener(this);
		div.addActionListener(this);
		eq.addActionListener(this);
		ce.addActionListener(this);
		ca.addActionListener(this);
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
		
		
		if(ae.getActionCommand()=="+"||ae.getActionCommand()=="-"||ae.getActionCommand()=="*"||ae.getActionCommand()=="/")
		{
			x=1;
			de=0;
			op=ae.getActionCommand();
			n=2;
			m=10;

		}
		else if(ae.getActionCommand()==".")
			de=1;
		else if(ae.getActionCommand()=="=")
		{
			n=1;
			x=2;
			switch(op)
			{
				case "+":c=a+b;break;
				case "-":c=a-b;break;
				case "*":c=a*b;break;
				case "/":c=a/b;break;
				default : break;
			}

		}
		else if(ae.getActionCommand()=="C")
		{
			if(n==1)
			{
				if(de==1)
				{
					m=m/10;
					a=a-(((a*m)%10)/m);
					
				}
				else
					a=(int)a/10;
			}
			else
			{
				if(de==1)
				{
					m=m/10;
					b=b-(((b*m)%10)/m);
					
				}
				else
				b=(int)b/10;
			}


		}
		else if(ae.getActionCommand()=="CA")
		{
			a=0;
			b=0;
			n=1;
			m=10;
			de=0;
			x=0;
		}
		else
		{
			for(int i=0;i<10;i++)
			{
				if(Integer.parseInt(ae.getActionCommand())==i)
				{
					if(n==1)
					{
						
						if(de==1)
						{
							y=Integer.parseInt(ae.getActionCommand());
							a=a+(y/m);
							m=m*10;
						}
						else
							a=a*10+Integer.parseInt(ae.getActionCommand());
							
					}
					else
					{
						if(de==1)
						{
							y=Integer.parseInt(ae.getActionCommand());
							b=b+(y/m);
							m=m*10;
						}
						else
						b=b*10+Integer.parseInt(ae.getActionCommand());
					}
				}
			}
		}
		if(x==0)		
			l.setText(String.valueOf(a));
		else if(x==1) 
			l.setText(String.valueOf(a)+op+String.valueOf(b));
		else if(x==2)
		{
			l.setText(String.valueOf(a)+op+String.valueOf(b));
			l2.setText(String.valueOf(c));
			x=0;
			a=0;
			b=0;
			m=10;
			de=0;

		}
	}
	public static void main(String args[])
	{
		FrameCalculator ob= new FrameCalculator();
	}

}