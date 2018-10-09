#include <bits/stdc++.h>

using namespace std;

struct node{
int data;
node* link;
};

struct node *START=NULL;
struct node *TOS=NULL;

void push(int data)
{
    node *temp=new node;
    temp->data=item;
    temp->link=NULL;

    if(START==NULL)
    {
        START=temp;
        TOS=temp;
        return ;
    }
    TOS->link=temp;
    TOS=temp;
}
int pop()
{

    if(START==NULL)
    {
        cout<<" UNDERFLOW condition \n";
        return -1;
    }

    node *ptr=START;
    node *prev=START;
    int data =TOS->data;

    if(TOS==START)
    {
        ptr=TOS;
        TOS=START=NULL;
        delete ptr;
        return data;
    }
    while(ptr->link !=NULL)
    {
        prev=ptr;
        ptr=ptr->link;

    }
    prev->link=NULL;
    delete ptr;

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
int display_top()
{
    return TOS->data;
}

int main(){
    int ch,data;

        cout<<"1. insert elements in stack"<<endl;
        cout<<"2. Display " <<endl;
        cout<<"3 . Exit "<<endl;
        cout<<"4. pop element  "<<endl;
        cout<<"5. Display Top "<<endl;

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
                cout<<" Top element is : "<<endl;

        }
    }


	return 0;
}



