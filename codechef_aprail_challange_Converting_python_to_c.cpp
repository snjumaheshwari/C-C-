int count(int indexes[],int m,int n)
{
    if(m==1){
            if(initial_arr[a[0]==max)
                return 0;
            else
                return 1;
            }
    else{
        n=0;
        int count=1;


        }

}

/*def count(indexes,m):
    n=len(indexes)
    if(n==1):
        if(initial_arr[indexes[0]]==m):
            return 0
        else:
            return 1
    else:
        copy_indexes = []
        count=1
        n=0
        for i in indexes:
            if(initial_arr[i]!=m):
                copy_indexes.append(i)
                n+=1
        if(not n):
            return 0
        for i in range(n-1):
            #print(indexes[i],indexes[i+1])
            for j in range(copy_indexes[i]+1,copy_indexes[i+1]):
                #print("under checking ",j,i)
                if(initial_arr[j]<m):
                    count+=1
                    #print("incremented")
                    break
        return count


test=int(input())
for i in range(test):
    n=int(input())
    initial_arr=list(map(int,input().split()))
    final_arr=list(map(int,input().split()))
    iszero=True
    isimpossible=False
    for i in range(n):
        x=initial_arr[i]-final_arr[i]
        if(x<0):
            isimpossible=True
            print("-1")
            break
        if(x!=0):
            iszero=False
    else:
        if(iszero):
            print("0")
        else:
            d=dict()
            for i in range(n):
                d[final_arr[i]]=d.get(final_arr[i],[])+[i]
            #print(d)
            ans=0
            for m in sorted(d.keys(),reverse=True):
                #print(m,d[m])
                a=count(d[m],m)
                for i in d[m]:
                    initial_arr[i]=0
                ans+=a
            print(ans)
*/

#include<bits/stdc++.h>


int main()
{
int test;
cin>>test;

while(test--)
    {


    }

}
