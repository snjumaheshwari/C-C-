#include<iostream>
#include<stdlib.h>
using namespace std;



// big o(1) -> front, push, insert + need only one variable LAST..

struct node{
    int data;
    node* link;
};
struct node *LAST=NULL;

void insert_item(int item)
{
    node *n1=new node();
    n1->data =item;

    if(LAST==NULL)
    {
        LAST=n1;
        n1->link=n1;
        return ;

    }
    n1->link=LAST->link;
    LAST->link=n1;
    LAST=n1;
}

int pop_item()
{
    if(LAST==NULL)
        return -1;
    if(LAST->link==LAST)
    {
        int item=LAST->data;
        delete(LAST);
        LAST=NULL;
        return item;

    }
    node* ptr=LAST->link;
    int item =ptr->data;
    LAST->link= ptr->link;
    delete(ptr);
    return item;

}


int front()
{
    if(LAST==NULL)
        return -1;
    return LAST->link->data;

}

int main()
{
    while(true)
    {
        int ch;
        cin>>ch;

        switch(ch)
        {
        case 1:
            int i;
            cin>>i;
            insert_item(i);
            break;
        case 2:
            cout<<endl<<"AT Front "<<front();
            break;
        case 3:
            cout<<endl<<"deleted item :"<<pop_item();
            break;
        case 4:
            exit(0);

        }
    }



}
