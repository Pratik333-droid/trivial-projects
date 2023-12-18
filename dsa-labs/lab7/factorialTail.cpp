#include <iostream>
using namespace std;

long double factorial(int num, long double result = 1)
{
    if (num == 1 || num == 0)
    return result;
    else 
    return (factorial(num-1, num*result));
}
int main()
{
    cout <<factorial(15);
    return 0;
}