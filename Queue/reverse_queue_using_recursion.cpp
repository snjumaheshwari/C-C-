#include<queue>
#include<iostream>
using namespace std;

void fun(queue<int> &Q)
{
    if(Q.empty())
        return;

    int item=Q.front();
    Q.pop();
    fun(Q);
    Q.push(item);

}
int main()
{
    queue <int> Q;
    for (int i=1;i<=5;i++)
        Q.push(i);
    fun(Q);

    while(!Q.empty())
    {
        cout<<Q.front()<<endl;
        Q.pop();

    }

    return 0;
}

