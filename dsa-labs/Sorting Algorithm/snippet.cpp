#include <iostream>
using namespace std;

void swap (int *a, int *b)
{
    int temp = *a;
    a= b;
    b = &temp;
}
int main ()
{
    int arr[4] = {1,2,3,4};
    for (int i = 0; i<4; i++)
    cout <<arr[i]<<"  ";
    cout <<endl;
    swap (&arr[0], &arr[1]);
    for (int i = 0; i<4; i++)
    cout <<arr[i]<<"  ";
    cout <<endl;
    return 0;
}