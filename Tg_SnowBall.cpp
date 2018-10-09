#include <bits/stdc++.h>
#define ll long long
#define DONE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 100000007

using namespace std;

int snowball(int input1,int size ,vector < int > input2)
{
	//Write code here
    int sum=0;
    int prev=0;

    for(int i: input2)
    {
        sum+= i;
        if(input1-sum>0)
            input1=input1-sum;
        else
            break;

    }
    for(int i: input2)
    {
        input1--;
        if(input1==0)
            {
                return i;
                break;
            }

    }

}


int main()
{
	DONE;

	int output;
    int ip1;
    cin >> ip1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip2_size = 0;
    cin >> ip2_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> ip2;
    int ip2_item;
    for(int ip2_i=0; ip2_i<ip2_size; ip2_i++) {
        cin >> ip2_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        ip2.push_back(ip2_item);
    }
    output = snowball(ip1,ip2_size,ip2);
    cout << output << endl;
    return 0;
	return 0;
}
