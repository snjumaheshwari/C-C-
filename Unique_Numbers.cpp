/*
Given an array of n numbers.
All Numbers are coming twice except 2 numbers  (which occur only once)
find them.

in O(n)time and O(1) space

first approach :-
we can make a dictionary and count the frequency of each elements of array..
then check corresponding frequency ..O(n+n) =O(n) Time
                                            O(n) Space..

Second Approach :-
if the unique number occur only once .. we could have taken x-or and that is the answer.

1.Take x-or of all numbers. let say x= x-or of all.
2. Divide the array into two halves..both containing one unique number
3. Take x-or of first half --->the other number is calculated by taking x-or with the x.
*/

#include<iostream>
using namespace std;


void find_unique(int *a,int n)
{
    int result=0;
     for(int i=0;i<n;i++)
        result^=a[i];
    // cout<<result<<endl;
    // find the rightmost set bit in res..
    int temp=result;
    int i=0;

    while(temp>0)
    {
        if(temp&1){
            break;
        }
        i++;
        temp=temp>>1;
    }
    int mask=(1<<i);
    // cout<<mask<<endl;
    int first=0;
    for(int i=0;i<n;i++)
    {
        if( (mask & a[i]) !=0)
            first=first^a[i];

    }
    int second=result^first;

    cout<<first<<" "<<second<<endl;

}

int main()
{
   int a[]={3,4,5,6,4,3,1,2,2,1};
   int n=sizeof(a)/sizeof(int);

    find_unique(a,n);
    return 0;
}
