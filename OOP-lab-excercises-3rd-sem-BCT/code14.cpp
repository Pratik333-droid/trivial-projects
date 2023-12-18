#include <iostream>

using namespace std;

class Unary
{
    int i= 0;
    public:
    void setter();
    void getter();
    void operator ++()
    {
        i+=4; //prefix operator 
        
    }

    void operator ++(int)
    {
        i+=5;
    }
    

};

void Unary :: setter ()
{
    cout << "Enter the value of i"<<endl;
    cin>> i;
}

void Unary :: getter()
{
    cout <<"The value of i is "<<i<<endl;
}
int main ()
{
    Unary u1;
    u1.setter();
    u1.getter();
    ++u1;
    
    u1.getter();
    u1++;
    u1.getter();

    return 0;
}



