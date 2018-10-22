#include<bits/stdc++.h>
using namespace std;


int gcd(int a ,int b)
{

	if(b==0)
		return a;

	return gcd(b, a%b);

}




void extended_gcd2(int a, int b, int&x, int &y,int &g)
{
	if(b==0)
	{
		g=a;
		x=1;
		y=0;
		return ;
	}
	int temp=a%b;
	extended_gcd2(b,temp,x,y,g);

	int cx= y;
	int cy= x- (a/b)* y;

	cout<<"intemediate values "<<cx<<" "<<cy<<endl;

	x=cx;
	y=cy;

}

int X,Y,G;
void extended_gcd(int a, int b)
{
	if(b==0)
	{
		G=a;
		X=1;
		Y=0;
		return ;
	}
	extended_gcd(b,a%b);



	int cx= Y;
	int cy= X- (a/b)* Y;
	cout<<"intemediate values "<<cx<<" "<<cy<<endl;


	X=cx;
	Y=cy;

}

int multiplicative_modulo(int a, int m)
{
	]extended_gcd(a,m);
	return (x + m)%m;
}
int gcd2(int a,int b)
{
	while(b!=0)
	{
		int temp=b;
		b=a%b;
		a=temp;

	}
	return a;
}

int lcm(int a,int b)
{
	int x= gcd(a,b);

	return (a*b)/x;
}
int main()
{

	int a,b;
	cin>>a>>b;

	//cout<<" GCD : "<<__gcd(a,b);
	int g=__gcd(a,b);

	cout<<" "<<gcd(a,b)<< "  "<<gcd2(a,b);

	cout<<"\n LCM :"<<lcm(a,b);

	int x,y;

	extended_gcd2(a,b,x,y,g);
	cout<<" x : y: "<<x<<" "<<y<<endl;

	extended_gcd(a,b);
	cout<<" "<<x<<" "<<y;

}