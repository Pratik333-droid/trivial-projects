#include <iostream>
using namespace std;

//wap to demonstrate the need of virtual destructor 
class Parent
{
    public:
    Parent()
    {
        cout <<"Inside the parent class constructor."<<endl;
    }

    ~Parent ()
    {
        cout <<"Inside the parent class destructor."<<endl;
    }

};

class Child : public Parent 
{
    public:
    Child ()
    {
        cout <<"Inside the child class constructor "<<endl;

    }
    ~Child ()
    {
        cout <<"Inside the child class destructor "<<endl;
    }
};

int main ()
{
   Parent *par = new Child; //since memory for the 
    // Parent par;
    // Child chi;

    return 0;
}