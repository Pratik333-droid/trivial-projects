#include <iostream>
using namespace std;
const float h = 0.1;
float slope (float a, float b)
{
//    return ((2*a-5)/(1-6*b)); 
    return (2*a-5);
}
int main()
{
    float k1, k2, k3, k4, m,x,y,xn,k;
    cout <<"Enter the starting point."<<endl;
    cin>>x>>y;
    cout <<"Enter the ending point."<<endl;
    cin>>xn;
    while (x<xn)
    {
        /* code */
        k1 = slope(x, y);
        k2 = slope(x+h/2, y+k1*h/2);
        k3 = slope(x+h/2, y+k2*h/2);
        k4 = slope(x+h, y+h*k3);
        k = (k1+2*k1+2*k3+k4)/6;
        y+=h*k;
        x+=h;
        cout <<"y = "<<y<<" at x = "<<x <<endl;

    }
    cout <<endl;
    cout <<"y = "<<y<<" at x = "<<x <<endl;
    
    return 0;
}