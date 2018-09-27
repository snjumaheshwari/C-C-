#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    int pr;
    node* link;
};
struct node* HEAD= NULL ;


void push( int data, int pr)
{
    node* n1= new node();
    n1->data=data;
    n1->pr=pr;

    if(HEAD== NULL)
    {
        // first node case..
        n1->link=NULL;
        HEAD=n1;
        return ;

    }
    if(pr > HEAD ->pr)
    {
        // insert at beginning..
        n1->link =HEAD;
        HEAD=n1;
        return ;
    }
    node * ptr =HEAD;
    node * prev=NULL;

    while(ptr!=NULL && ptr->pr >= pr)
    {
        prev=ptr;
        ptr=ptr->link;
    }
    // insert between prev and ptr(ptr at NULL If end)
        n1-> link=ptr;
        prev->link=n1;

}


node* front_node()
{
    if(HEAD==NULL)
        return NULL;
    return HEAD;

}
int front_element()
{
    if(HEAD==NULL)
        return -1;
    return HEAD->data;

}

int pop()
{
    if(HEAD==NULL)
    {
        cout<<" NO item found ";
        return -1;
    }
    node *ptr= HEAD;
    HEAD=HEAD->link;
    int item=ptr->data;
    delete(ptr);
    return item;
}

void display()
{
    node * ptr =HEAD;
    while(ptr !=NULL)
    {
        cout<<"DATA : "<< ptr->data<< " PRIORITY : "<< ptr->pr<<"\n";
        ptr=ptr->link;

    }
}



int main()
{
    // make main function yourself for testing purpose..
    int data;
    int pr;

    cout<<" which function to call ? \n";
    cout<<" 1. front of priority queue \n";
    cout<<" 2. display queue \n" ;
    cout<<" 3. insert in the priority queue \n";
    cout<<" 4. pop in priority queue \n";
  //  cout<<" 5.delete entire list \n";
    cout<<" 0. exit\n";

    int ch;
    while(true)
    {
        cout<< "\n enter your choice : ";
        cin>> ch;

        switch(ch)
        {
        case 1:
            cout<<"\n Front of priority queue:"<<front_element();
            break;
        case 2:
            cout<<"\n Display priority Queue :\n";
            display();
            break;
        case 3:
            cout<<"\n Insert in linked list";
            cout<<"\n Enter Data :";
            cin>>data;
            cout<<"\n Enter Priority ";
            cin>> pr;
            push(data, pr);
            break;
        case 4 :
            cout<<"\n Deletion from priority queue";
            data=pop();
            break;

        case 0:
            exit(0);
        }

    }
    return 0;
}

