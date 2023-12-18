#include <iostream>
#include <cmath>
using namespace std;

float functionValue (float x)
{
    return (x*x* cos(x) - x* cos(x));
}

float differentiation (float a)
{
    return ((functionValue(a+0.001)- functionValue (a))/0.001);
}
void findRoot (float a, float tol)
{
    int count = 0;
    float root;
    while (abs(functionValue(a))> tol && count < 25)
    {
        count +=1;
        root = a - (functionValue (a)/differentiation(a));
        a = root;
    }
    cout <<"One of the roots of the given equation is "<<root<<endl;
    cout <<"Root is calculated after "<<count <<" iterations "<<endl;
}
int main ()
{
    float a, tol;
    cout <<"Enter the assumed root"<<endl;
    cin>>a;
    cout <<"Enter the tolerance level"<<endl;
    cin>>tol;
    findRoot(a, tol);
    return 0;
}