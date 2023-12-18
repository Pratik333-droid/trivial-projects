#include <iostream>
using namespace std;
// const float h = 0.01;
// f(x,y) = x+y
// f(0) = 0
float function(float a, float b)
{
    return ((a-b)/(a+b));
}
int main ()
{
    float x, y, h, xn;
    cout <<"Enter the initial values of x and y, the step size h and the final value xn"<<endl;
    cin>>x>>y>>h>>xn;
    while(x < xn)
    {
        cout <<"x = "<<x <<" for y = "<<y<<endl;
        y = y+ (function(x, y))*h;
        x+=h;
    }
    cout <<"y = "<<y<<" at x = "<<x<<endl;
    return 0;
}