import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.util.*;
/*<applet code = "Calculator.class" width="500" height="250"></applet>*/
public class Calculator extends Applet implements ActionListener{
	int x,de,n,m;
	double a,b,c,y;
	String op;
	Button add,sub,div,mul,eq,ce,ca,d;
	Button[] num = new Button[10];

	public void init() 
	{
		de=0;n=1;m=10;
		for(int i=0;i<10;i++)
		{
			num[i] = new Button(Integer.toString(i));
			add(num[i]);
			num[i].addActionListener(this);
		}
		add = new Button("+");
		sub = new Button("-");
		mul = new Button("*");
		div = new Button("/");
		eq = new Button("=");
		ce = new Button("clear");
		ca = new Button("clear all");
		d = new Button(".");
		add(d);
		add(add);
		add(sub);
		add(mul);
		add(div);
		add(eq);
		add(ce);
		add(ca);
		d.addActionListener(this);
		add.addActionListener(this);
		sub.addActionListener(this);
		mul.addActionListener(this);
		div.addActionListener(this);
		eq.addActionListener(this);
		ce.addActionListener(this);
		ca.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae) {
		
		
		if(ae.getActionCommand()=="+"||ae.getActionCommand()=="-"||ae.getActionCommand()=="*"||ae.getActionCommand()=="/")
		{
			x=1;
			de=0;
			op=ae.getActionCommand();
			n=2;
			m=10;

		}
		else if(ae.getActionCommand()==".")
		{
			de=1;


		}
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
		else if(ae.getActionCommand()=="clear")
		{
			if(n==1)
			{
				if(de==1)
				{
					m=m/10;
					a=a-(((a*m)%10)/m);
					
				}
				else
					a=a/10;
			}
			else
			{
				if(de==1)
				{
					m=m/10;
					b=b-(((b*m)%10)/m);
					
				}
				else
				b=b/10;
			}


		}
		else if(ae.getActionCommand()=="clear all")
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
		repaint();
	}
	public void paint (Graphics g){
		if(x==0)
			g.drawString(String.valueOf(a),150,110);
		else if(x==1) 
			g.drawString(String.valueOf(a)+op+String.valueOf(b),150,110);

		else if(x==2)
		{
			g.drawString(String.valueOf(a)+op+String.valueOf(b)+"="+String.valueOf(c),150,110);
			x=0;
			a=0;
			b=0;
			m=10;
			de=0;

		}


	}
}