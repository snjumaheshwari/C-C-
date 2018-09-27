// array.. :- binary search..
			// sort : bubble, inserstion , selection, merge , quick sort..
						
#include<iostream>
using namespace std;

int binary_search(int a[],int item,int begin,int end)
{
	// search in sorted array..(in descending order)
	if(begin>end)
		return -1 ;
	
	int mid=(begin+end)/2;
	
	if(item==a[mid])
	{
		cout<<"element found at "<<mid+1<<" position ";
		return mid;
	}
		if(item>a[mid])
			return binary_search(a,item,begin,mid-1);
		else
			return binary_search(a,item,mid+1,end);
	
}

// bubble sort :-

void bubblesort(int a[],int n)
{
	// descending order...
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if(a[i]>a[j])  // for ascending order change > to <..
			{
				// swap..
				int temp;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

//  inserstion sort :- in descending order
void insertionsort(int a[], int n)
{
	for(int i=1;i<n;i++)
	{
		int item=a[i];
		int j=i-1;
		while(j>=0)
		{
			if(item<a[j])
			{
				break;
			}
	
			a[j+1]=a[j];
			j--;	
		}	
	a[j+1]=item;
	
	}	
}

// selection sort :-

void selectionsort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int item=a[i];
		int largest=a[i+1];
		int pos=i+1;
		for (int j=i+1;j<n;j++ )
		{
			if(a[j]>largest)
			{
				largest=a[j];
				pos=j;
			}
		}
		if(largest>item)
		{
			// swap..a[i] (item)  and a[pos] (smallest)
			int temp=a[pos];
			a[pos]=a[i];
			a[i]=temp;
			
		}
		
	}
}


// mergesort ..
void merge(int a[],int l,int m,int r)
{
	
	int n1=m-l+1;
	int n2=r-m;
	int L[n1], R[n2];
	
	for(int i=0; i<n1 ; i++)
	{
		L[i]=a[l+i];
	}
	
	for(int i=0; i<n2 ;i++)
	{
		R[i]=a[m+1+i];
	}
	
	int k=l,i=0,j=0;
	while(i<n1 && j<n2)
	{
		
		if(L[i]>=R[j])
		{
			a[k]=L[i];
			i++;	
		}
		else 
		{
			a[k]=R[j];
			j++;	
		}	
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		k++;
		j++;
	}
	
}
void mergesort(int a[],int begin,int end)
{

	if(begin>=end)
	{
		return ;
	}
	int mid=(end+begin)/2;
	mergesort(a,begin, mid);
	mergesort(a,mid+1,end);
	merge(a,begin,mid,end);
	
}

int main()
{
	int n;
	cout<<" enter no of elements : ";
	cin>>n;
	int a[n];
	
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	// use any one of the sorting..
	//selectionsort(a,n);
	//insertionsort(a,n);
	//bubblesort(a,n);
	
	mergesort(a,0,n-1);

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
	int item;
	cout<<" enter item to search : ";
	cin>>item;
	int x=binary_search(a,item,0,n-1);
	if(x==-1)
	cout<<"item not found ";
		
}
