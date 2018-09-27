//stack using linked list..

// queue using two stacks..

#include<iostream>
using namespace std;


struct node{
		long int info;
		node *link;
		
};

class stack{
	public:
	node* START;
	
	stack()
	{
		START=NULL;
	 } 
	 void push( int item);
	  int pop();
	 void display();
	 
};

void stack::push(int item)
{
	// inserting from begining of linked list ..
	node * n1=new node;
	n1->info=item;
	n1->link=NULL;
	
	if(START==NULL)
	{
		START=n1;
		return;
	}
	
	n1->link=START;
	START=n1;
	
}

int stack::pop()
{
	// deleteing from the begigning of the linked list..
	
	if(START==NULL)
	{
		cout<<endl<<"UNDERFLOW"<<endl;
		return -1;	
	}	
	if(START->link==NULL)
	{
		long int item=START->info;
		START=NULL;
		return item;		
	}
	
		int item=START->info;
		START=START->link;
		return item;
}

void stack::display()
{
	if(START==NULL)
	{
		cout<<endl<<" EMPTY"<<endl;
		return;
	}
	cout<<endl<<"ELEMENTS ARE :-"<<endl; 
	node *ptr=START;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<" ";
		ptr=ptr->link;
	}
}

//***************************************************************************************//


class queue{
	stack s1; // s1 is main list..
	stack s2;
	 //s2 is auxialry ..to implement pop operation.
	public:
		
	int pop();
	void push(int item);
	void display();
};

void queue::push( int item)
{
	s1.push(item);
}

int queue::pop()
{
	// first moving to stack 2..and then 
	// deleteing from the begigning of the linked list.. of stack 2..
	// then again move to stack1..
	
	while(s1.START!=NULL)
	{
		int item=s1.pop();
		s2.push(item);
	}
	
	int item=s2.pop();
	
	while(s2.START!=NULL)
	{
		int item=s2.pop();
		s1.push(item);
	}
	
}

void queue::display()
{
s1.display();
}


int main()
{	
	// all set.. do whatever u want..
	// front of the queue is displayed last..
	
	queue q1;
	q1.push(23);
	q1.push(24);
	q1.display();
	q1.push(45);
	
	q1.display();
	int x;
	x=q1.pop();
	q1.display();
	
}
