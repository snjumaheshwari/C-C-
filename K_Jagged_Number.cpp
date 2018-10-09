#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;


/*
	a number n is said to be k- jagged number if
		smallest prime factor of n is greater than or equal to k.

*/

int smallest_prime_factor(int num)
{
	// num should be greater than 1.

	for(int i=2;i*i<=num;i++){
		if(num%i==0)
			return i;
	}
	return num;

}

bool is_jagged(int n,int k)
{
	int i=2;
	for(; i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(i<k)
				return false;
			else
				return true;
		}

	}
	if(n<k)
		return false;
	return true;

}

void print_first_n_k_jagged_numbers(int n,int k)
{
	int count =0;
	int i=1;
	while(count<=n)
	{	
		if(is_jagged(i,k))
		{
			cout<<i<<" ";
			count++;
		}
		i++;
	}


}

int main()
{
	DONE
	int n,k;
	cin>>n>>k;
	/*
	if(is_jagged(n,k))
		cout<<n<<" is "<<k <<" jagged number\n";
	else
		cout<<n<<" is not "<<k <<" jagged number\n";

	*/

	print_first_n_k_jagged_numbers(n,k);
	


	return 0;
}