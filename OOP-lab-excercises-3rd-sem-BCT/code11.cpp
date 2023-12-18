#include <iostream>
using namespace std;

// exception order of constructor and destructor invocation order in multilevel inheritence

class GrandDaddy
{
    int age, children, grand_children;
    public:
    GrandDaddy()
    {
        age = 80;
        children = 5;
        grand_children = 10;
        cout <<"Inside the unparameterized constructor of the GrandDaddy class "<<endl;

    }
    GrandDaddy (int a, int c, int gc)
    {
        age = a;
        children = c;
        grand_children = gc;
        cout <<"Inside the parameterized constructor of the GrandDaddy class "<<endl;
    }

    ~GrandDaddy()
    {
        cout <<"Destructor of the GrandDaddy class invoked "<<endl;
    }
};
class Child : public GrandDaddy
{
    int no_of_child;
    public:
    Child ()
    {
        no_of_child = 2;
        cout <<"Inside the unparameterized constructor of the child class"<<endl;
    }
    Child (int n, int o, int p, int q) : GrandDaddy (o, p, q)
    {
        no_of_child = n;
        cout <<"Inside the parameterized constructor of the child class"<<endl;

    }
    ~Child ()
    {
        cout <<"Destructor of the Child class invoked "<<endl;
    }
};

class GrandChild : public Child
{
    int agee;
    public:
    GrandChild()
    {
        agee = 10;
        cout <<"Inside the unparameterized constructor of the GrandChild class "<<endl;
    }
    GrandChild (int ages, int p, int q, int r, int s) : Child (p,q,r,s)
    {
        agee = ages;
        cout <<"Inside the parameterized constructor of the GrandChild class "<<endl;
    }
    ~GrandChild()
    {
        cout <<"Destructor of the GrandChild class invoked "<<endl;
    }

};
int main ()
{
    GrandChild g1, g2(10,40, 80, 5,8);   // the input order in the object is grandchild's age, father's age, grand father's age, no of child of grand
                           // father and no of grand children of grandfather
    return 0;
}