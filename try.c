//#include<bits/stdc++.h>
#include<stdio.h> // => printf   scanf
#include<stdlib.h> // => malloc calloc realloc and free ar
#include<conio.h> // =>  getche,getch

void fun(int n)
{
    if(n==10)
        return;
    else
        printf("%d\n",n);
        fun(n+1);
}

void sscanf_test()
{
    char *s="Hello World";
    char s1[20];
    int len= sscanf(s,"%s",s1);
    printf("%s : %d",s1,len);

    // Hello :1
}
void name_reverse()
{int i;
    char a[]={'s','a','n','j','a','y'};

	int l=5;

	for(i=0;i<=l/2;i++)
	{
		//swap ..a[i]  and a[l-i]
		char c=a[i];
		a[i]=a[l-i];
		a[l-i]=c;
	}
	printf("%s",a);
}
void nested_printf()
{
    int x=25;
    printf("%d\n",printf("%d\n",printf("%d\n",x)));

}
void char_to_ascii()
{
    printf("=%d",getche());
}

void printf_from_if_and_else_both()
{

    if(printf("Nihal ") && 0)
    {

    }
    else
        printf("Jaiswal\n");

    if(! printf("Sanjay"))
    {

    }
    else
    {
    printf("Maheshwari\n");
    }

}

void add_without_additional_operator()
{
    int a;
    int b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);

    printf("%d\n",a&b);
    printf("%d\n",a|b);

}

void comapre_equal_or_not_using_bitwise()
{
    int a;
    int b;
    scanf("%d %d",&a,&b);
    if(!(a^b))
        printf("No are equal");
    else
        printf("No are not equal");

}
void compare_same_no_of_different_datatypes()
{
    float a=1.9;
    double b=1.9;
    (a==b) ? printf("Equal\n") : printf("Not Equal\n") ; // not equal printed..

    float x=2;
    double y=2;
    int z=2;

    (x==y) ? printf("Equal\n") :printf("Not Equal\n");  // equal printed..

    (x==z) ? printf("Equal\n") :printf("Not Equal\n"); // equal printed..

    (y==z) ? printf("Equal\n"):printf("Not Equal\n");  // equal printed..

}

void structure_union_size_locha()
{
    struct st{
        int a;
        char b;
    };
    union un{
        int a;
        char b;
    };
    struct st s;
    union un u;
    printf("%d\n",sizeof(s)); // 8
    printf("%d\n",sizeof(u));  //4

    printf("%d %d \n",sizeof(s.a),sizeof(s.b));  // 4 1
    printf("%d %d \n",sizeof(u.a),sizeof(u.b));  // 4 1

}

void fibonacci_upto_n_terms()
{
    int n,i ;
    scanf("%d",&n);
    printf("%d\n",n);
    // int a[]=new int[n];
    int *p=(int *) malloc(n*sizeof(int));

    *(p+0)=0;        //a[0]=0;
    *(p+1)=1;        //a[1]=1;
    for(i=2;i<n;i++)
    {
    //a[i]=a[i-1]+a[i-2];
    *(p+i)=*(p+i-1)+*(p+i-2);
    }

    for( i=0;i<n;i++)
        printf("%d ",*(p+i));
    free(p);
}

void scanf_with_slash_n(){
    int a;
// scanf("%d\n\n",&a);
// it asks for 2 inputs ... and a will take first one..
 // printf("a is %d ",a);

 // one more experiment :-
 scanf("\n\n\n%d",&a); // it works fine.. no problem..(ask for one input and take that)
 printf("a is %d ",a);
}

void using_malloc_calloc_and_realloc_free()
{


}
void practise_pre_post()
{

    int i=6;
    int j=i++ + ++i + i++ +i++;
    printf("%d ",j);
}
int main()
{
//compare_same_no_of_different_datatypes();
//structure_union_size_locha();
//fibonacci_upto_n_terms();
//scanf_with_slash_n();
//char_to_ascii();
//practise_pre_post();
//sscanf_test();
return 0;
}
