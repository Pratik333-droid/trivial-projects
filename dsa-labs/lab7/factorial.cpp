/*
WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING USING RECURSION:
a. FIND THE FACTORIAL FOR GIVEN NUMBER ‘N’.
b. FIND THE FIBONACCI NUMBER FOR GIVEN TERM ‘N’.
c. SOLVE ABOVE QUESTIONS (a And b) USING TAIL RECURSION.
d. SOLVE TOWER OF HANOI PROBLEM FOR ‘N’ DISCS.
*/
#include <iostream>
using namespace std;

long int factorial(long int n)
{
    if (n==1 || n==0)
    return 1;
    else 
    return (n*factorial(n-1));
}
int main()
{
    cout <<"The factorial of 10 is "<<factorial(10)<<endl;
    cout <<"The factorial of 5 is "<<factorial(5)<<endl;
    cout <<"The factorial of 9 is "<<factorial(9)<<endl;
    cout <<"The factorial of 1 is "<<factorial(1)<<endl;
    cout <<"The factorial of 0 is "<<factorial(0)<<endl;
    return 0;
}