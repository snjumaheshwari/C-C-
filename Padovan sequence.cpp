#include<bits/stdc++.h>
using namespace std;


int main(){
	int x;
	float y;
	cin>>x>>y;

	if(x%5 !=0){
		printf("%.2f\n",y);
	}
	else{

		if(y-0.5-x>=0){
			printf("%.2f\n",y-0.5-x);
		}
		else{
			printf("%.2f\n",y);
		}

	}
	return 0;


}