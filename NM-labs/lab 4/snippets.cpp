#include <iostream>
using namespace std;

void displayData (int arr[2])
{
    cout <<"Displaying data:"<<endl;
    cout <<arr[0]<<" "<<arr[1]<<endl;
}
int main ()
{
    int array[2] = {1,2};
    displayData (array);
    return 0;
}