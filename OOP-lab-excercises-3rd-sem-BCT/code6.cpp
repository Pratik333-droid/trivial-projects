#include <iostream>
using namespace std;

class Parent 
{
    int par;
    public:
    Parent ()
    {
        cout <<"Inside the parent class default constructor "<<endl;
    }
    Parent (int a)
    {
        par = a;
        cout <<"Inside the parent class constructor where the value of parent variable is "<<par<<endl;
    }
};

class Child : public Parent
{
    int chi;
    public:
    Child ()
    {
        cout <<"inside the default constructor of the child class "<<endl;
    }
    Child (int b): chi(b), Parent (b)
    {
        // Parent = b;
        // chi = b;
        cout <<"Inside the child class constructor where the value of child variable is "<<chi<<endl;
    }
};

int main ()
{

    Parent par1 (5);
    Child chi1 (6);
    Child bachha;
    return 0;
}
