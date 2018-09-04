#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define mp make_pair
#define pb push_back
#define p(k) printf("%d ",k)
#define pl(k) printf("%lld ",k)
#define pn(k) printf("%d\n",k)
#define pln(k) printf("%lld\n",k)
#define ps(str) printf("%s",str)
#define s(k) scanf("%d",&k)
#define sl(k) scanf("%lld",&k)
#define ss(str) scanf("%s",str)
#define ft first
#define sd second

using namespace std;

struct node{
int data;
node* link;
};

struct node* START=NULL;

void insert_begin(int item)
{
        node* ptr=new node;
        ptr-> data=item;
        ptr->link=NULL;

        if(START==NULL)
        {
                START=ptr;
                return ;
        }
        ptr->link=START;
        START=ptr;
}

void insert_end(int item)
{
    node *temp=new node;
    temp->data=item;
    temp->link=NULL;

    if(START==NULL)
    {
        START=temp;
        return ;
    }
    node *ptr=START;
    while(ptr->link !=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;


}
void display()
{
    node *ptr=START;
    if(ptr==NULL)
        {
            cout<<" No elements in Linked List";
             return ;
        }
    cout<<" Elements in Linked List are : ";
    while(ptr!=NULL)
    {
        cout<< ptr->data <<" ";
        ptr=ptr->link;
    }
    cout<<endl;

}

int delete_begin()
{
    if(START==NULL)
        {
            cout<<" No item in Linked List";
            return -1;
        }
    node *ptr=START;
    START=START->link;

    int item=ptr->data;

    delete ptr;

    return item;
}
int main(){
    int ch,data;

        cout<<"1. insert elements in begin"<<endl;
        cout<<"2. Display " <<endl;
        cout<<"3 . Exit "<<endl;
        cout<<"4. Delete "<<endl;
        cout<<"5. insert elements in end" <<endl;


    while(1)
    {
        cout<<"\n Enter Choice : ";

        cin>>ch;
        cout<<"\n";
        switch(ch)
        {
            case 1:
                    cout<<"enter data"<<endl;
                    cin>>data;
                    insert_begin(data);
                    break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            case 4:
                cout<<delete_begin();
                break;
            case 5:
                cout<<"enter data"<<endl;
                cin>>data;
                insert_end(data);
                break;
        }
    }


	return 0;
}



