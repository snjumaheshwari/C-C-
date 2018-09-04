#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};
struct node* HEAD=NULL;
struct node* TAIL=NULL;

void enq(int data)
{
    node *n1=new node();
    n1->data=data;
    n1->next=NULL;

    if(HEAD==NULL ||  TAIL==NULL)
    {

        HEAD=n1;
        TAIL=n1;
        return;
    }
    TAIL->next=n1;
    TAIL=n1;
}
int deq()
{
    if(HEAD==NULL || TAIL ==NULL)
    {
        return -1;
    }
    node *ptr=HEAD;
    int data=ptr->data;
    HEAD=HEAD->next;
    free(ptr);
    return data;
}

bool isempty()
{
    if(HEAD==NULL || TAIL==NULL)
        return true;
    return false;
}
int fro_ele()
{
    if(HEAD==NULL)
        return -1;
    return HEAD->data;
}

void display()
{
    node *ptr=HEAD;
    while(ptr!=NULL)
    {


    }

}
int main()
{
    int ch;
    cout<<"1 . Enque \n 2. Deque.\n 3 isempty \n 4. front element \n 5. exit\n";
    while(true)
        {

        cin>>ch;
        switch(ch):
            {
                case 1:
                        int item;
                        cout<<" enter item\n";
                        cin>>item;
                        enque(item);
                        break
                case 2:


            }

        }
    return 0;
}

