
#include<bits/stdc++.h>
using namespace std;


void generate_permutation(char *a, int i,int j)
{
    if(a[i]=='\0')
    {
        a[j]='\0';
        cout<<a<<"\n";
        return;
    }

    for(int j=i;a[j]!='\0';j++)
    {
        swap(a[i],a[j]);
        generate_permutation(a,i+1,j+1);
        swap(a[j],a[i]);
    }
}

void subset(char *a, char* b,int i,int j)
{
     if(a[i]=='\0')
    {
        b[j]='\0';
        cout<<b<<endl;
        return;
    }

    b[j]=a[i];
    subset(a,b,i+1,j);
     subset(a,b,i+1,j+1);
}

int main()
{
   // ios::sync_with_stdio(false);
    //cin.tie(NULL);

    char a[] ="abc";
    char b[]="";

    subset(a,b,0,0);
  generate_permutation(a,0,0);
    return 0;
}
