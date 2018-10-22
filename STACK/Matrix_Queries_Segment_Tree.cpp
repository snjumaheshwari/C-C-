#include<bits/stdc++.h>
#define ll long long
using namespace std;


int r;

void buildTree(vector<vector<vector<int>>> &A, int s,int e, vector<vector<vector<int>>> &Tree, int index)
{
    if(s==e)
        {
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    Tree[index][i][j]= A[s][i][j];
            return;
        }
    int mid= (s+e)/2;
    buildTree(A, s,mid,Tree,index*2);
    buildTree(A, mid+1,e,Tree,index*2+1);
    
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                Tree[index][i][j]= ( Tree[index][i][j]+ ( Tree[2*index][i][k] * Tree[2*index+1][k][j] )%r )%r;
            }
            
        }
    }
    
}


vector<vector<int>>  Query( vector<vector<vector<int>>> &Tree, int ss,int se,int qs,int qe, int index)
{
    if(ss>= qs && se<= qe)
    {
        return Tree[index];
    }
    if(ss> qe || qs > se)
    {
        
        vector<vector<int>> I(2);
        I[0][0]=1;
        I[0][1]=0;
        I[1][0]=0;
        I[1][1]=1;
        return I;
    }
    int mid= (ss+se)/2;
    
    vector<vector<int>> Left= Query(Tree, ss,mid,qs,qe,2*index);
    vector<vector<int>> Right= Query(Tree,mid+1,se,qs,qe,2*index+1);
    
    vector<vector<int>> ans(2);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                 ans[i][j]=  (ans[i][j]+ ( Left[i][k] * Right[k][j] )%r )%r;
    return ans;
}
int main() {
    int n,q;
    
    int x,y,z,w;
    cin>>r>>n>>q;
    
    vector<vector<vector<int>>> A;
    
    for(int i=0;i<n;i++)
    {
        vector<vector<int>> V;
        
        vector<int> v0,v1;
        cin>>x>>y>>z>>w;
        v0.push_back(x);
        v0.push_back(y);
        v1.push_back(z);
        v1.push_back(w);
        V.push_back(v0);
        V.push_back(v1);
        A.push_back(V); 

    }
    vector<vector<vector<int>>> Tree(4*n+1);
    buildTree(A,0,n-1,Tree,1);
    
    for(int i=0;i<7;i++)
    {
        cout<<Tree[i][0][0]<< " "<< Tree[i][0][1] << " "<< Tree[i][1][0]<<" "<<Tree[i][1][1]<<endl;
    }
    int l,r;
   while(q--)
    {
        cin>>l>>r;
        vector<vector<int>> V;
        
        V=Query(Tree,0,n-1,l,r,1);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<V[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
	return 0;
}