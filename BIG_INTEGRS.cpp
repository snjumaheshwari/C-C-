
/*
In Java, Python it is easy to work with big integer but in C++
it's difficult because the long long int data type can store
 only at max 18 digits..
 So, for problems involving BigNumbers(containing 100's of digits)
 we either use Java Big Integer Class or python or we use Arrays in C++ !

 Note :- There is a BOOST C++ Library which allows us to work with big integers as well.

*/


//Computing Large Factorials in C++ !


void factorial(int number)
{
    // assuminhg
    int *a=new int[1000]{0};

    a[0]=1;
    int n=1; // which deonots the index of the array ,before which we have stored some digits..

    for(int i=2;i<=number;i++)
    {
        multiply(a,n,i);
    }

}
