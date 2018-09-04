#include<iostream>
using namespace std;

/*
def fun(arr):
	#find the maximum contigeous sum of subarray in linear time using kadene's algorithm
	maximum=0
	s=0
	for i in arr:
		s=s+i
		if(s>maximum):
			maximum=s
		if(s<0):
			s=0
	return maximum
	*/

int main()
{

    int arr[]={1,100,-102,4,500,6};
    int n=sizeof(arr)/ sizeof(arr[0]);

    int maximum=arr[0];
    int s=arr[0];

    for(int i=1;i<n;i++)
    {
        s+=arr[i];
        if(s>maximum)
            maximum=s;
        if(s<0)
            s=0;
       // cout<<s<<" ";
    }
    cout<<maximum<<" ";
}
