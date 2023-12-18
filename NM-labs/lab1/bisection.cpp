#include <iostream>
#include <cmath>
using namespace std;
// find the root of the equation x^2 cosx + x sinx using the bisection method
float functionValue (float x)
{
    return (x* cos(x) - x* sin(x));
    // return (pow(x,3)- 3*x - 9);
}
void findRoots (float a, float b, float err, float iteration)
{
    float mid_value, f_mid_value;
    int count = 1;
    if (functionValue(a)*functionValue(b)>0)
    {
        cout <<"Invalid interval."<<endl;
        goto end;
    }
    mid_value = (a+b)/2;
    
    while (abs(functionValue(mid_value)) > err && iteration > count)
    {
        if (functionValue (a)* functionValue (mid_value) < 0)
        {
            b = mid_value;
            mid_value = (a+b)/2;
        }
        else
        {
            a = mid_value;
            mid_value = (a+b)/2;
        }
        count +=1;
    }

    cout <<"One of the roots of the given equation in the given interval is "<<mid_value<<endl;
    cout <<"This value was calculated after "<<count<<" iterations"<<endl;
    end:;
        


}
int main ()
{
    float a,b,err, steps;
    cout <<"Enter the opening interval a"<<endl;
    cin>>a;
    cout <<"Enter the closing interval b"<<endl;
    cin>>b;
    cout <<"Enter the error tolerance "<<endl;
    cin>>err;
    steps = log (abs(b-a)/err)/log(2);
    findRoots (a, b, err, steps);
    return 0;
}