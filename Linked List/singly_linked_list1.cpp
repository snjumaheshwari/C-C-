#include<bits/stdc++.h>
#define INF 1000000
using namespace std;


struct node{
    int data;
    node * next;
};

int length_of_linked_list(struct node *head)
{
    struct node* ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;

    }
    return count;
}

void insert_in_linked_list(node **head , int data, int position)
{
    node* n1=new node();
    n1->data=data;
    int k=1;
    node* ptr= *head;

    if(position ==1 ){
        // inserting at beginning..
        n1->next=ptr;
        *head=n1;
        return ;
    }
    node *prev= NULL;
    while(ptr != NULL && k<position)
    {
        k++;
        prev=ptr;
        ptr=ptr->next;

    }
    prev->next=n1;
    n1->next=ptr;
}

void display(node ** head)
{
    node *ptr= *head;
    while(ptr!=NULL)
    {
        cout<< ptr->data <<" ";
        ptr=ptr->next;

    }
}

void delete_from_linked_list(node **head, int position)
{
    node* ptr= *head;
    if(ptr == NULL)
    {
        cout<<" Empty List\n";
        return;
    }

    if(position ==1)
    {
            // delete from beginning..
            *head = (*head) -> next;
            delete(ptr);
            return ;
    }
    int k=1;
    node *prev=NULL;
    while(ptr != NULL && ( k< position))
    {
        k++;
        prev=ptr;
        ptr=ptr-> next;
    }

    if(ptr == NULL && position!= INF)
        cout<< " Position does not exist ";
    else
        {
        prev->next=ptr->next;
        delete(ptr);
        }

}
void delete_list()
{


}

int main()
{
    // make main function yourself for testing purpose..
    struct node* head=NULL;
    int data;
    int position ;

    cout<<" which function to call ? \n";
    cout<<" 1. length of linked list \n";
    cout<<" 2. display linked list \n" ;
    cout<<" 3. insert in the linked list \n";
    cout<<" 4. deletion in linked list \n";
    cout<< "5.delete entire list \n";
    cout<<" 0. exit\n";

    int ch;
    while(true)
    {
        cout<< "\n enter your choice : ";
        cin>> ch;

        switch(ch)
        {
        case 1:
            cout<<"\n Length of linked list is :"<<length_of_linked_list(head);
            break;
        case 2:
            cout<<"\n Display Linked List :";
            display(&head );
            break;
        case 3:
            cout<<"\n Insert in linked list";
            cout<<"\n Enter Data :";
            cin>>data;
            cout<<" Enter Position :( 1. beginning  -1. end  n for nth position between beginning and end)\n";
            cin>>position ;
            if(position ==-1)
                position =INF;
            insert_in_linked_list(&head, data, position);
            break;
        case 4 :
            cout<<"\n Enter position to be deleted ( 1. beginning -1 end .. n general )";
            cin>>position ;
            if(position ==-1)
                position = INF;
            delete_from_linked_list(&head,position);
            break;
        case 5:
            cout<<"\n  delete entire list";
            delete_list();
        case 0:
            exit(0);
        }

    }
    return 0;
}
