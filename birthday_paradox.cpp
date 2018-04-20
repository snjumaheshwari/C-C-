#include<iostream>
using namespace std;


void find_n_for_given_prob(float prob)
{
// find minimum number of people required ..
// such that their is prob % probability of having 2 people
// same birthday..
// Eg:- 50 % => 23
// Eg :- 90 % => 41
// Eg :- 100 % => 366
}
void find_prob_for_given_n()
{
int num=365;
int den=365;
float p;
for(int i=1;i<=n;i++)
{
    p=p*(num)/den;
    cout<<" for "<< i<<" people there is "<<1-p<<"probability of same bday";


}


}
int main()
{

float num=365;
float den=365;

float p=1; // probability of different birthday
int i=1;
while(p>0.9)
{   num--;
    p=p*(num/den);
    i++;
    cout<<p<<" " <<i<<endl;
}


cout<<i<<endl;
}
