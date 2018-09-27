
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N=0;
struct node{
    int data;
    node* left;
    node* right;
};
struct node* START=NULL;
struct node* END=NULL;
struct node* MID=NULL;

void enque(int item)
{
    N++;
    node *n1=new node();
    n1->data=item;
    n1->left=NULL;
    n1->right=NULL;

    if(START==NULL)
    {
        START=n1;
        END=n1;
        n1->left=NULL;
        n1->right=NULL;
        MID=n1;
        return;
    }

    END->right=n1;
    n1->left=END;
    END=n1;
    if(N&1)
    {
        MID=MID->right;
    }

}

void print_middle()
{
    if(MID==NULL)
    {
        cout<<"-1"<<endl;

    }
    else
        cout<<(MID->data)<<endl;

}

void print_front()
{

    if(START==NULL)
    {
        cout<<"-1"<<endl;

    }
    else{
        cout<<(START->data)<<endl;
    }
}

void print_last()
{
    if(END==NULL)
        cout<<"-1"<<endl;
    else
        cout<<(END->data)<<endl;

}

int remove_mid()
{

    node *ptr=MID;
    if(MID==NULL)
        return -1;

    int item=ptr->data;

    if(N&1)
    {
        MID=MID->left;
    }
    else{
        MID=MID->right;
    }
    N--;

    if(START==END)
    {
        START=NULL;
        END=NULL;
        MID=NULL;
        delete(ptr);
        return item;
    }

    ptr->right->left=ptr->left;
    if(ptr->left!= NULL)
        ptr->left->right= ptr->right;

    return item;

}

void display()
{
    cout<<"display";
    node*ptr=END;
        while(ptr!=NULL)
        {

            cout<<(ptr->data);
            ptr=ptr->left;
        }


}

int main()
{
    ll n,item;
    cin>>n;
    for (ll i=0;i<n;i++)
    {
        cin>>item;
        enque(item);
    }
  //  display();
    ll q;
    cin>>q;
    while(q--)
    {
        int ch;
        cin>>ch;

        switch(ch)
        {

        case 1:
            cin>>item;
            enque(item);
           // display();
            break;
        case 2:
            print_middle();
            break;
        case 3:
            print_front();
            break;
        case 4:
            print_last();
            break;
        case 5:
            cout<<remove_mid()<<endl;
            break;
        }

    }

    return 0;
}
