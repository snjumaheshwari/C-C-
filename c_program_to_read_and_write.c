#include<stdio.h>
#include<conio.h>

int main()
{
	int i=4;
	double d=6.0;
	char s[]="hackerrank";
int i2;
double d2;
char s2[100]; // this is not scalable for input of unknown size

// Read inputs from stdin
scanf("%d", &i2);
scanf("%lf", &d2);
scanf("%*[\n] %[^\n]", s2); //  =getline(cin >> ws, s2); // eat whitespace

// Print outputs to stdout
printf("%d\n", i + i2);
printf("%.01lf\n", d + d2); // cout << fixed << setprecision(1) << d + d2 << endl;

printf("%s%s", s, s2);
return 0;
}
