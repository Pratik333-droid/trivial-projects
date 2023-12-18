#include <iostream>
using namespace std;

class Base 
{
    int j;
    public:
    virtual void printStuff()
    {
        cout <<"Inside the base class de bruino "<<endl;
    }
    void setData ();
    void getData ();
};

void Base :: setData ()
{
    cout <<"Enter j"<<endl;
    cin >>j;
}

void Base :: getData ()
{
    cout <<"The value of j is " <<j<<endl;
}

class Derived : public Base
{
    public:
    void printStuff()
    {
        cout <<"Inside the derived class "<<endl;
    }
    void print();
};
void Derived :: print ()
{
    cout <<"Code testing code testing"<<endl;
}
int main ()
{
    Base b1;
    Derived d1;
    d1.printStuff();
    // d1.setData();
    // d1.getData();
    // d1.Base::printStuff();
    Base *bp1;
    bp1 = &d1;
    bp1->printStuff();
    // bp1->print(); // base class can't access the derived class member functions and data
    d1.print();
    return 0;

}