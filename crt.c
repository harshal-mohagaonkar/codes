#include<stdio.h>
int multinv(int A3, int B3);
void crt();
void main()
{
	int result;
	crt();
}
void crt()
{
	int n,N,N1,N2,N3,n1,n2,n3,b1,b2,b3;
	int A1,A2,A3,y1,y2,y3,Q,B1,B2,B3,T1,T2,T3,ANS;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the value of remainder b1, b2,b3\n");
	scanf("%d%d%d",&b1,&b2,&b3);
	printf("enter the value of divisor n1, n2,n3\n");
	scanf("%d%d%d",&n1,&n2,&n3);
	N=n1*n2*n3;
	printf("N=%d\n",N);
	N1=N/n1;
	printf("N1=%d\n",N1);
	N2=N/n2;
	printf("N2=%d\n",N2);
	N3=N/n3;
	printf("N3=%d\n",N3);
	//---------------------------------
	A3=n1;
	B3=N1;
	y1=multinv(A3,B3);
	
	printf("y1=%d\n------------------------------------\n",y1);
	//-----------------------------------
	A3=n2;
	B3=N2;
	y2=multinv(A3,B3);
	printf("y2=%d\n-------------------------------------\n",y2);
	//------------------------------------------
	A3=n3;
	B3=N3;
	y3=multinv(A3,B3);
	printf("y3=%d\n---------------------------------------\n",y3);
	//--------------------------------------------
	ANS=((y1*b1*N1)+(y2*b2*N2)+(y3*b3*N3))%N;
	printf("\nANS=%d\n",ANS);
	
}
int multinv(int A3, int B3)
{
	int A1,A2,Q,B1,B2,T1,T2,T3,temp;
	temp=A3;
	A1=1;
	A2=0;
	B1=0;
	B2=1;
	while(B3 != 1)
	{
		
		Q=A3/B3;
		printf("Q=%d\t",Q);
		printf("A1=%d\t",A1);
		printf("A2=%d\t",A2);
		printf("A3=%d\t",A3);
		printf("B1=%d\t",B1);
		printf("B2=%d\t",B2);
		printf("B3=%d\t",B3);
		T1=A1-(Q*B1);
		printf("T1=%d\t",T1);
		T2=A2-(Q*B2);
		printf("T2=%d\t",T2);
		T3=A3-(Q*B3);
		printf("T3=%d\n",T3);
		A1=B1;
		A2=B2;
		A3=B3;
		B1=T1;
		B2=T2;
		B3=T3;
	}
	printf("\n------------------------------------\n");
	if(B2>0)
	{
		return B2;
	}
	else
	{
		return (temp+B2);
	}
	printf("\n------------------------------------\n");
}
/*
pooja@ubuntu:~$ gcc crt.c
pooja@ubuntu:~$ ./a.out
enter the value of n
3
enter the value of remainder b1, b2,b3
1
6
8
enter the value of divisor n1, n2,n3
5
7
11
N=385
N1=77
N2=55
N3=35
Q=0	A1=1	A2=0	A3=5	B1=0	B2=1	B3=77	T1=1	T2=0	T3=5
Q=15	A1=0	A2=1	A3=77	B1=1	B2=0	B3=5	T1=-15	T2=1	T3=2
Q=2	A1=1	A2=0	A3=5	B1=-15	B2=1	B3=2	T1=31	T2=-2	T3=1

------------------------------------
y1=3
------------------------------------
Q=0	A1=1	A2=0	A3=7	B1=0	B2=1	B3=55	T1=1	T2=0	T3=7
Q=7	A1=0	A2=1	A3=55	B1=1	B2=0	B3=7	T1=-7	T2=1	T3=6
Q=1	A1=1	A2=0	A3=7	B1=-7	B2=1	B3=6	T1=8	T2=-1	T3=1

------------------------------------
y2=6
-------------------------------------
Q=0	A1=1	A2=0	A3=11	B1=0	B2=1	B3=35	T1=1	T2=0	T3=11
Q=3	A1=0	A2=1	A3=35	B1=1	B2=0	B3=11	T1=-3	T2=1	T3=2
Q=5	A1=1	A2=0	A3=11	B1=-3	B2=1	B3=2	T1=16	T2=-5	T3=1

------------------------------------
y3=6
---------------------------------------

ANS=41

*/


