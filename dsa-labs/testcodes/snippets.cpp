#include <iostream>
using namespace std;

void function(int data)
{
    while (data<50)
    {
        data++;
        if (data == 5)
        {
            cout <<"5 detected. Returning the value."<<endl;
            return; // this will break the loop and return the value
        }
    }
    cout <<"Will this be printed?"<<endl;
}
int main ()
{
    
    function(1);
    cout <<"I think this will be executed."<<endl;
    function(3);
    return 0;
}