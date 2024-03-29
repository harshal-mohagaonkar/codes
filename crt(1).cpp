
#include<iostream>
using namespace std;
int euclid(int m,int b)
{
int A1,A2,A3,B1,B2,B3,T1,T2,T3,Q;
A1=1,A2=0,A3=m,T1=T2=T3=0;
B1=0,B2=1,B3=b,Q=0;
B1=0,B2=1,B3=b;
cout<<"\n"<<"Q"<<"\t"<<"A1"<<"\t"<<"A2"<<"\t"<<"A3"<<"\t"<<"B1"<<"\t"<<"B2"<<"\t"<<"B3"<<"\t"<<"T1"<<"\t"<<"T2"<<"\t"<<"T3"<<"\n";
cout<<Q<<"\t"<<A1<<"\t"<<A2<<"\t"<<A3<<"\t"<<B1<<"\t"<<B2<<"\t"<<B3<<"\t"<<T1<<"\t"
<<T2<<"\t"<<T3<<"\n";
while(true)
{
if(B3==0)
{
return (0);
}
if(B3==1)
{
if(B2<0)
{
B2=m+B2;
}
return(B2);
}
Q=A3/B3;
T1=A1-Q*B1;T2=A2-Q*B2;T3=A3-Q*B3;
A1=B1;A2=B2;A3=B3;
B1=T1;B2=T2;B3=T3;
cout<<Q<<"\t"<<A1<<"\t"<<A2<<"\t"<<A3<<"\t"<<B1<<"\t"<<B2<<"\t"<<B3<<"\t"<<T1<<"\t"
<<T2<<"\t"<<T3<<"\n";
}
}
int chinese(int x[10],int a[10],int n)
{
int N=1;
int M[10];
int z[10];
int y[10];
for(int i=0;i<n;i++)
{
N=a[i]*N;}
cout<<"\n"<<"STEP:2\n";
cout<<"\n"<<"N="<<N<<"\n";
for(int i=0;i<n;i++)
{
M[i]=N/a[i];
}
cout<<"\n"<<"M1="<<M[0]<<"\n"<<"M2="<<M[1]<<"\n"<<"M3="<<M[2]<<"\n";
cout<<"\n"<<"STEP:3";
for(int i=0;i<n;i++)
{
cout<<"\n"<<"y"<<i+1<<"="<<"Inverse"<<"("<<M[i]<<")mod("<<a[i]<<")\n";
}
cout<<"\n"<<"STEP:4\n";
for(int i=0;i<n;i++)
{
cout<<"\n"<<"m="<<a[i]<<"\t"<<"b="<<M[i]<<"\n";
z[i]=euclid(a[i],M[i]);
cout<<"\n"<<"Multiplicative Inverse ="<<z[i]<<"\n";
cout<<"-------------------------------------------------------------------------------";
if(z[i]==0)
{
break;
}
}
int X=0;
for(int i=0;i<n;i++)
{
X=X+(x[i]*M[i]*z[i]);
}
cout<<"\n"<<"STEP:5"<<"\n";
cout<<"\n"<<"X="<<"(X+(x[i]*M[i]*z[i]))%N";
X=X%N;
cout<<"\n"<<"X="<<X%N<<"\n";
return X;
}
int main()
{
int x[10],q[10];
int n;
cout<<"Enter the no. of equations:";
cin>>n;
cout<<"Enter the values:";
cout<<"\n";
for(int i=0;i<n;i++)
{
cin>>x[i];
}
cout<<"Enter the modular values:";cout<<"\n";
for(int i=0;i<n;i++)
{
cin>>q[i];
}
cout<<"Values entered are";
cout<<"\n";
for(int i=0;i<n;i++)
{
cout<<"X="<<x[i]<<"(mod"<<q[i]<<")"<<"\n"<<"\n";
}
cout<<"\n"<<"STEP:1\n";
for(int i=0;i<n;i++)
{
cout<<"\n"<<"b"<<i+1<<"="<<x[i]<<"\t";
cout<<"n"<<i+1<<"="<<q[i]<<"\n";
}
int ans=chinese(x,q,n);
cout<<"\nTherefore value of X is--->>"<<ans<<endl;
}

/*OUTPUT:
info12@info12-HP-280-G2-MT:~/Desktop$ g++ crt.cpp
info12@info12-HP-280-G2-MT:~/Desktop$ ./a.out
Enter the no. of equations:3
Enter the values:
1
6
8
Enter the modular values:
5
7
11
Values entered are
X=1(mod5)
X=6(mod7)
X=8(mod11)
STEP:1
b1=1 n1=5
b2=6 n2=7
b3=8 n3=11STEP:2
N=385
M1=77
M2=55
M3=35
STEP:3
y1=Inverse(77)mod(5)
y2=Inverse(55)mod(7)
y3=Inverse(35)mod(11)
STEP:4
m=5 b=77
Q
0
0
15
2 A1
1
0
1
-15
A2
0
1
0
1
A3
5
77
5
2
B1
0
1
-15
31
B2
1
0
1
-2
B3
77
5
2
1
T1
0
1
-15
31
T2
0
0
1
-2
T3
0
5
2
1
Multiplicative Inverse =3
-------------------------------------------------------------------------------
m=7 b=55
Q
0
0
7
1
A1
1
0
1
-7
A2
0
1
0
1
A3
7
55
7
6
B1
0
1
-7
8
B2
1
0
1
-1
B3
55
7
6
1
T1
0
1
-7
8
T2
0
0
1
-1
T3
0
7
6
1
Multiplicative Inverse =6
-------------------------------------------------------------------------------
m=11 b=35
Q
0
0
3
5
A1
1
0
1
-3
A2
0
1
0
1
A3
11
35
11
2
B1
0
1
-3
16
B2
1
0
1
-5
B3
35
11
2
1
T1
0
1
-3
16
T2
0
0
1
-5
Multiplicative Inverse =6
-------------------------------------------------------------------------------
STEP:5
X=(X+(x[i]*M[i]*z[i]))%N
X=41
Therefore value of X is--->>41
T3
0
11
2
1*/
