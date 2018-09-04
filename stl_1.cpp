#include<bits/stdc++.h>
using namespace std;


// write a function that prints the array.. irrespective of it's type..

template<class T>
void printArray( T arr[],int n)
{

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int a[]={1,2,3,4,5,6};

    char b[]="abcdef";

    float c[]={1.2,3.4,5.6,7,8.0,9.1};

    printArray(c,6);

    return 0;
}
