#include<bits/stdc++.h>
using namespace std;


int next_greater(vector<int> arr, int item, int n){

    int s=0;
    int e= n-1;

    while( s<=e){
        int mid=(s+e)/2;

        if(arr[mid] > item &&  (mid==0 or arr[mid-1]<= item )){
            return mid;
        }
        else if(arr[mid] <= item){

            s=mid+1;
        }
        else{

            e= mid-1;
        }
    }
    return s;

}

int main(){

    int t,item; cin>>t;
    while(t--){
       int n; cin>>n;
       int m=0;

       vector<int> arr;
        cin>>item;
        arr.push_back(item);
        m++;

       for(int i=1;i<n;i++){

            cin>>item;
            if(item >= arr[m-1]){

                arr.push_back(item);
                m++;
            }
            else{
                    int pos=upper_bound(arr.begin(), arr.end(),item)- arr.begin();

                    arr[pos]=item;
            }


       }

    cout<<m<<" ";
       for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
       }


    cout<<endl;

    }


    return 0;
}
