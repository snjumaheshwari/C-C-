#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
   /* int a= 10;
    double b= 5.16;
    double c;

    c=a+ (500+b);

    cout<<c;
*/
int t; cin>>t;

while(t--)
{

    float n; cin>>n;
    float gross_sal=0;
    if(n<1500)
    {
        cout<<2*n<<endl;
    }
    else
    {
        gross_sal= 1.98 *n;
        // cout<<gross_sal+d<<endl;
        printf("%.2f\n",gross_sal+500);
    }
   

}

    return 0;
}