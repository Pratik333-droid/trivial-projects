#include <iostream>
using namespace std;

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int array[5])
{
    cout <<"The elements of the array are:"<<endl;
    for (int i =0; i<5; i++)
    cout <<array[i]<<"   ";
    cout <<endl;
}
int main()
{
    int ar[5] = {1,2,3,5,4};
    display(ar);
    swap(&ar[3], &ar[4]);
    display(ar);
    return 0;
}