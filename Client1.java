import java.io.*;  
import java.util.Scanner;
import java.net.*;  
public class Client1{  
public static void main(String[] args){  
Scanner in = new Scanner(System.in);
try{  
ServerSocket ss=new ServerSocket(6666);  
Socket s=ss.accept();//establishes connection 
DataOutputStream dout=new DataOutputStream(s.getOutputStream());    
DataInputStream dis=new DataInputStream(s.getInputStream());  

int e=Integer.parseInt(dis.readUTF());
System.out.println("Encryption process !!!!");
System.out.println("Public Key is:= "+e);
int n=Integer.parseInt(dis.readUTF());
System.out.println("Enter the plain text:= ");
int PT=in.nextInt();
int e1=1;
for(int i=0;i<e;i++)
{
e1=(e1*PT)%n;
}

PT=e1;
int CT=(PT)%n;
System.out.println("Cipher text is := "+CT);
dout.writeUTF(Integer.toString(CT));  

ss.close();  
}catch(Exception e){System.out.println(e);}  
}  
}  
