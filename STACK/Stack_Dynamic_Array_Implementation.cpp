#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 100000007
#define MAXSIZE 20

using namespace std;

/*

    Time Complexity :-
        pop,IsEmptyStack, IsFullStack,size-ofStack,Top,DeleteStack => O(1)
        Push => O(1) (average)
            1+ 2+ 4+ 8+ 16 +    ... + N/2 +N = 2N
            => O(2N) for N Push

        PrintStack => O(N)

    Space Complexity => O(N)
*/

class Stack{
	int top; // top stores the last index of stack array .. if arr is empty it is -1

	int capacity; // capacity of stack array
	int* arr; // stack array

public:

	Stack()
	{
		top=-1;
		capacity=1;
		arr=new int[capacity];
	}

	bool IsEmptyStack()
	{
		return top==-1;
	}
	bool isFullStack()
	{
	    // if capacity is 5 and top=4 that means (0,1,2,3,4) all the array is filled.
		return top== capacity-1;
	}
	int sizeofStack()
	{
	    // top is index starting from 0
		return top+1;
	}

    void DoubleStack()
    {
        int *ptr=new int[capacity*2];

        for(int i=0;i<=top;i++)
        {
            ptr[i]=arr[i];
        }
        delete(arr);
        arr=ptr;

    }

	void push(int item)
	{
		if(isFullStack())
		{
            DoubleStack();
		}
		top++;
		arr[top]=item;
	}
	int pop()
	{
		if(IsEmptyStack())
		{
			cout<<"\nStack UnderFlow";
			return -1;
		}
		int item=arr[top];
		top--;
		return item;
	}

	void PrintStack()
	{
	    cout<<"\n Elements in Stack are : ";
		for(int i=0;i<=top;i++)
			cout<<arr[i]<<" ";
	}

	void DeleteStack()
	{
		free(arr);
	}
	int Top()
	{
		return arr[top];
	}
};


int main()
{

	Stack s1;

	int ch,data;

	 cout<<"0. Exit "<<endl;
     cout<<"1. insert elements in stack"<<endl;
     cout<<"2. Display " <<endl;
     cout<<"3. pop element  "<<endl;
     cout<<"4. Display Top "<<endl;
     cout<<"5. Is empty Stack ?"<< endl;
     cout<<"6. Is Full Stack ?"<<endl;
     cout<<"7. Size Of stack"<<endl;
     cout<<"8. Delete Stack"<<endl;

    while(1)
    {
        cout<<"\n Enter Choice : ";

        cin>>ch;
        cout<<"\n";
        switch(ch)
        {
        	case 0:
                exit(0);
            case 1:
                    cout<<"enter data"<<endl;
                    cin>>data;
                    s1.push(data);
                    break;

            case 2:
                s1.PrintStack();
                break;

        	case 3:
        		cout<<" Item popped :"<<s1.pop()<<"\n";
        		break;

        	case 4:
                cout<<s1.Top()<<endl;
                break;

            case 5:
             	if(s1.IsEmptyStack())
             		cout<<"Yes, stack is empty\n";
             	else
             		cout<<"No, stack is not empty\n";
             	break;

             case 6:
         		if(s1.isFullStack())
             		cout<<"Yes, stack is FULL\n";
             	else
             		cout<<"No, stack is not FULL\n";

             	break;
           	case 7:
           		cout<<"\nSize of Stack "<<s1.sizeofStack()<<endl;
           		break;

           	case 8:
           		s1.DeleteStack();
           		break;

        }

	}
	return 0;
}

