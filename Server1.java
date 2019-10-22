import java.io.*;  
import java.net.*;
import java.util.Scanner;  
public class Server1{  

public static void main(String[] args) {  
Scanner in = new Scanner(System.in);
try{      
Socket s=new Socket("localhost",6666);  
DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
DataInputStream dis=new DataInputStream(s.getInputStream());  
int e=2,e1=1,d=0,count;
int PT,CT;
      System.out.println("Enter two prime numbers:= ");
 int p = in.nextInt();
 int q = in.nextInt();
 System.out.println("p:= "+p);
 System.out.println("q:= "+q);
 int n=p*q;
 int Q=(p-1)*(q-1);
 System.out.println("n:= "+n);
 System.out.println("Q:= "+Q);

    while(e<Q){
    count = gcd(e,Q);
    if(count==1)
        break;
    else
        e++;
    }
int j;
for(j=1;j<Q;j++)
{
	if((Q*j+1)%e==0)
	{
	d=(Q*j+1)/e;
	break;
	}
}
System.out.println("Private Key:= "+d);
System.out.println("Public Key:= "+e);
dout.writeUTF(Integer.toString(e));
dout.writeUTF(Integer.toString(n));

CT=Integer.parseInt(dis.readUTF());


for(int i=0;i<d;i++)
{
	e1=(e1*CT)%n;
}
CT=e1;
int PT1=(CT)%n;
System.out.println("Decryption process !!!!");
System.out.println("Plain text is :="+PT1);



dout.flush();  
dout.close();  
s.close();  
}catch(Exception e){System.out.println(e);}  
}  
  

public static int gcd(int a, int h) 
{
    int temp;
    while(true)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
}
