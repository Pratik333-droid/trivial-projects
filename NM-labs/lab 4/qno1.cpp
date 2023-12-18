#include <iostream>
#include <cmath>
using namespace std;
// y = f(x) = x + x sin(x)
float function (float val)
{
    return (val - val * log(pow(val,2)));
}
int main ()
{
    float a, b, x, error, denominator;
    cout <<"Enter the interval a and b"<<endl;
    cin>>a>>b;
    cout <<"Enter the error tolerance"<<endl;
    cin>>error;
    int count = 0;
    while (count<100 )
    {
        denominator = function(a) - function (b);
        if (fabs(denominator)<0.001)
        {
            cout <<"Solution can't be worked out. "<<endl;
            exit(0);
        }
        
        x = (a * function (b) - b * function (a))/denominator;
        a = b;
        b = x;
        count ++;
        if (fabs(function(x))< error)
        break;
    }

    cout <<"One of the roots is approximately "<<x<<" and the error is "<<function(x)<<endl;

    return 0;
}