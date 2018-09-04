#include<bits/stdc++.h>
using namespace std;


// write a program to remove all the elements of an array which are less than 20.
template <class T>
void printArray( T arr[],int n)
{

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

bool isToBeRemoved(int n)
{
    if(n<20) return true;
    return false;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int a[]={10,15,20,30,40,50,60};
    int n=sizeof(a)/sizeof(int);

    remove_if(a,a+n,isToBeRemoved);



    printArray(a,n-2);

    return 0;
}
