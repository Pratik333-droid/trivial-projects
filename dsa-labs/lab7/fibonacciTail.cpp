#include <iostream>
using namespace std;

long double fibonacci (int num, long double a=0, long double b =1)
{
    if (num == 0)
    return a;
    else if (num == 1)
    return b;
    else
    return fibonacci(num-1, b, a+b);
}
int main ()
{
    cout <<"The 15th fibonacci number is "<<fibonacci(15)<<endl;
    cout <<"The 16th fibonacci number is "<<fibonacci(16)<<endl;
    return 0;
}