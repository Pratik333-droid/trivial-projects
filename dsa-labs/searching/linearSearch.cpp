//a program to demonstrate linear search
#include <iostream>
using namespace std;

int linearSearch (int leng, int array[], int key)
{
    for (int i = 0; i<leng; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {4,7,-8,3,12,0,-66,124,1080,222,67,54};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = linearSearch(n, arr, -6);
    (index== -1)? cout <<"The entered element is not found."<<endl:cout <<"Required index = "<<index<<endl;
    return 0;
}