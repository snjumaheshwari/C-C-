#include<iostream>
using namespace std;


struct node{
    int data;
    node* link;
};

struct node* TOS=NULL;

void push(int data)
{
    // Insert at the Beginning of Linked List

    node *n1=new node();
    n1->data=data;

    n1->link=TOS;
    TOS=n1;

}

int isEmptyStack()
{
    return TOS==NULL;
}

int pop()
{
    // remove from beginning..
    if(isEmptyStack())
    {
        cout<<" Stack Underflow \n";
        return -1;

    }
    node *temp=TOS;

    int item=TOS->data;
    TOS=TOS->link;
    delete(temp);
    return item;

}
int top()
{
    if(isEmptyStack())
        return -1;
    return TOS->data;
}


int main()
{




}
