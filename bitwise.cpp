/*
why bitwise operator
// bitwise operator are very fast..

suppose bitwise operator take n time..
then
/ * takes n**2 time..
% takes n**3 time..

 & bitwise and
 | bitwise or
 ^ bitwise x-or
 >> right shift
 << left shift

 question . 1 you are given an array i which every number occur twice except one.
 find that number ?
 */

 // solution :- just x-or all the numbers..

 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
     int N;
     cin >>N;

     int a[N];

     for (int i=0;i<N;i++)
        cin>>a[i];

    int ans=0; // 0^n=n
                // n ^n =0

    for(int i=0;i<N;i++)
    {
        ans^=a[i];
    }
    cout<<ans<<endl;
    return 0;
 }
