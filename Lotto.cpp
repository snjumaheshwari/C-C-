 // ADHOC BRUTE FORCE..

// Lotto(HackerBlocks)
/*
In the German Lotto you have to select 6 numbers from the set (12,49).
A popular strategy to play lotto- although it doesn't increase your chances of winning-
is to select a subset S containing k (k>6) of these 49 numbers.. and
then play several games with choosing numbers only from S.

for example, for k=8 and S=f1: 2,35,8,13,21,34
    there are 28 possible games :[1,2,3,5,8,13]
                                [1,2,3,5,8,21]
                                ..
                                [3,5,8,13,21,34]
                                8Choose 6

Your job is to write a program that reads in the number k and
the set S and then prints all possible games choosing numbers
only from S.

*/
#include<iostream>
using namespace std;
int main()
{
 // Numbers from 1 to 49..
 // choose a subset of 6 numbers..

 int a[]={1,2,4,5,6,7,8,10,12};
 int n=sizeof(a)/sizeof(int);

 for(int i=0;i<n-5;i++)
 {
     for(int j=i+1;j<n-4;j++)
     {
         for(int k=j+1;k<n-3;k++)
         {
            for(int l=k+1;k<n-2;k++)
            {
                for(int m=l+1;m<n-1;m++)
                {
                    for(int o=m+1;o<n;o++)
                    {
                        cout<<endl<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<" "<<a[m]<<" "<<a[o];
                    }

                }
            }

         }
     }

 }

}
