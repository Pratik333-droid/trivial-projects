#include <iostream>
using namespace std;
// casting primitive to non-primitive data types and vice versa
class Base
{
    int x;
    public:
    Base(){}
    Base (int abc)
    {
        x = abc;
    }
    void setData(int);
    int getData();
    operator int ()
    {
        return x;
    }
};
void Base :: setData(int p) 
{
    x = p;
    
}
int Base :: getData()
{
    return x;
}
int main ()
{
    Base b, cobj, copyobj;
    b.setData(1);
    int var;
    var = b;
    cout <<"Value of var variable is "<<var<<endl;
    int intvar= 8;
    cobj = intvar;
    cout <<"the value of cobj is "<<cobj.getData()<<endl;
    copyobj = cobj;
    cout <<"the value of copyobj is "<<copyobj.getData()<<endl;
    return 0;
}
