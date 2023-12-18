#include <iostream>
#include <cmath>

using namespace std;

class Distance 
{
    float x,y;
    public:
    void getData ();
    void setData ();
    float operator - (Distance);
};

void Distance :: setData ()
{
    cout <<"Enter the x co-ordinate "<<endl;
    cin>>x;
    cout <<"Enter the y co-ordinate "<<endl;
    cin>>y;

}

void Distance :: getData ()
{
    cout <<" x = "<<x<<endl;
    cout <<" y = "<<y<<endl;
}

float Distance :: operator- (Distance dist)
{
    return (pow(pow(x-dist.x, 2) + pow(y- dist.y, 2), 0.5));
}

int main ()
{

    Distance d1,d2;
    cout <<"Enter first coordinates "<<endl;
    d1.setData();
    cout <<"Enter second coordinates "<<endl;
    d2.setData();
    cout <<"The entered coordinates are "<<endl;
    d1.getData();
    d2.getData();
    cout <<"The distance between the entered coordinates are "<<(d2-d1)<<" units."<<endl;
    return 0;
}