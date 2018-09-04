#include<bits/stdc++.h>
using namespace std;

/*
    Enumeration or enum is user defined data type in c  ( Just like structure and union)
    It is used to assign names to integral constant ( IMPORTANT)
    The names make program easy to read and maintain..

*/

// EXAMPLE :-
enum state{ working=1, failed=0};
enum result{PASS,FAIL} r1;

enum State(WORKING,FAILED,FREEZED);
enum state s1;

enum day{mon=1,tue,wed,thrusday=50,friday,saturday,sunday};
enum month{Jan=1, Feb, Mar, Apr, May, Jun, Jul,Aug, Sep, Oct, Nov, Dec};

void fun1()
{
    enum day d;
    d=wed;

    printf("%d ",d); //3

    enum day d2=thrusday;
    printf("The day number stored in d2 is %d",d2);
}

void fun2()
{
    enum  month m1;

    for(int i=Jan;i<=Dec;i++)
    {
        printf("%d ",i);
    }

}

void fun3()
{
    // two enum name can have the same values..
    // Example :- enum state{working=1, not_working=0, stopped=0 };

    // all enum constant must be unique in their scope
    enum result{ passed=1,failed=0};
    // same as :-

    //const int passed=1;
    // const int failed=0;



   // enum state{ working,failed=0};  // will generate error
    // enum mission{ success,failed}; // same .. will generate error

}

void fun4()
{

    // enum values are integers .. and constants.. i.e. if not => error
}

void fun5()
{



}
int main()
{
    //fun1();
 //   fun2();

 // fun3();
}
