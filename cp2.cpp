#include<bits/stdc++.h>
#define Done ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main()
{
	int t ;
	cin>>t ;
	while(t--){

	int a1,a2,a3;  cin>>a1>>a2>>a3;
	int b1,b2,b3;  cin>>b1>>b2>>b3;
	int c1,c2,c3;  cin>>c1>>c2>>c3;

	int s1=a1+a2+a3;
	int s2=b1+b2+b3;
	int s3=c1+c2+c3;

	if(s1==s2 ||  s2==s3 || s3==s1)
		{
			cout<<"no"<<endl;
		}

	else if(a1>=b1 && a2>=b2 && a3>= b3 && a1>=c1 && a2>= c2 && a3>=c3)
	{
		if((b1>=c1 && b2>=c2 && b3>=c3) || (c1>= b1 && c2>=b2 && c3>=b3)){
			cout<<"yes"<<endl;
		}
		else
			cout<<"no"<<endl;
	}


	else if(b1>=a1 && b2>=a2 && b3>= a3 && b1>=c1 && b2>= c2 && b3>=c3)
	{
		if((a1>=c1 && a2>=c2 && a3>=c3) || (c1>= a1 && c2>=a2 && c3>=a3)){
			cout<<"yes"<<endl;
		}
		else
			cout<<"no"<<endl;
	}

	else if(c1>=b1 && c2>=b2 && c3>= b3 && c1>=a1 && c2>= a2 && c3>=a3)
	{
		if((b1>=a1 && b2>=a2 && b3>=a3) || (a1>= b1 && a2>=b2 && a3>=b3)){
			cout<<"yes"<<endl;
		}
		else
			cout<<"no"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}

}

return 0;


}