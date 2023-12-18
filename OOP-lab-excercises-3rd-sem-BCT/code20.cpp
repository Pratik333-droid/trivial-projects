#include <iostream>
#include <cmath>
using namespace std;
template <class T>
T power (T base, int exp)
{
    T result;
    result = pow (base, abs(exp));
    return result;

}

int main ()
{
    int  exp_var = 5;
    int  base_var = 2;
    cout <<base_var <<" raised to the power "<< exp_var<<" equals "<< power <int> (base_var, exp_var)<<endl;
    float base_varf = 3.3;
    cout <<base_varf<<" raised to the power "<<exp_var <<" equals "<<power <float> (base_varf, exp_var)<<endl;
    return 0;

}