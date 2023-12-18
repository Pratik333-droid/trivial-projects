#include <iostream>
using namespace std;
//return nth fibonacci number
long int fibonacci (long int n)
{
    if (n== 1 || n == 2)
    return 1;
    else
    return (fibonacci(n-1) + fibonacci(n-2));
}
int main()
{
    cout <<"The 10 fibonacci number is "<<fibonacci(10)<<endl;
    cout <<"The 5th fibonacci number is "<<fibonacci(5)<<endl;
    return 0;
}