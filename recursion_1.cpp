// CPP - UNDERSTANDING RECURSION
/*
	What is recursion ?
	Recursion in computer science is a method where the solution to a 
	problem
	depends on solutions to smaller instances of the same problem.

	Parts Of Recursive Algorithm:
	1. Base Class
	2. Work Toward Base case
	3. recursive call ( i.e. call overselves..)

	The work toward base case is where we make the problem simpler.
	The recursive call,is where we use the same algorith to solve a 
	simpler version of the problem.
	The base case is the solution to the simplest possible solution.

	-----------------------------------------------------------------
	How to solve Recursion ?

	1. Figure out the base case ..
	2. assume sub problem can be solved automatically. 
		=> induction hypothesis.. assume f(k) is True (found)

	3. find f(k+1) or f(2k) i.e bigger problem

		n ! -> n==0 => return 1 
					else return n ! = n * (n-1)!
*/

#include <bits/stdc++.h>
#define ll long long
#define MeTime 
using namespace std;

ll factorial(int n)
{
	if(n==0)
		return 1;
	else
		return n* factorial(n-1);

}

int main()
{
	MeTime;
	int n; cin>>n;
	cout<< factorial(n);

	return 0;
}