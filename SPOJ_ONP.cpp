#include<bits/stdc++.h>
using namespace std;

int main()
{

	int t;
	cin>>t;

	stack<char> st;

	string s;
	while(t--)
	{
		cin>>s;

		for(int i=0;i<s.length();i++)
		{

			if(s[i]=='(')
				continue;
			else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
			{ 
				st.push(s[i]);
			}
			else if(s[i]==')')
			{
				cout<<st.top();
				st.pop();
			}
			else
			{
				cout<<s[i];
			}

		}
		cout<<endl;		
	}
	return 0;

}