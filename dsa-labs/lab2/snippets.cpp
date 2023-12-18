#include <iostream>
using namespace std;

int main ()
{
    int arr[2];
    for (int i =0; i<10; i++)
    {
        // cout <<"Enter the element"<<endl;
        arr[i] =i;
    }
    for (int i =2; i<4; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}