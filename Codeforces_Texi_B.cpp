#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	int a[n];
	int b[5];
	b[0]=b[1]=b[2]=b[3]=b[4]=0;

	for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
		}

	int count= b[4]+b[3];

	b[1]= max(0,b[1]-b[3]);
	count+= ceil((float)b[2]/2);

	if(b[2]%2==1)
		b[1]=max(0,b[1]-2);
	count+= ceil((float)b[1]/4);
	cout<<count<<endl;
	return 0;
}