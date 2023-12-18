//A program to demonstrate binary search using iterative approach
#include <iostream>
using namespace std;

int binarySearch (int len, int array[], int key)
{
    int upper = len -1;
    int lower = 0;
    int mid_val;
    while (lower<= upper)
    {
        mid_val = (upper + lower)/2;
        if (key<array[mid_val])
        upper = mid_val-1;
        else if (key > array[mid_val])
        lower = mid_val+1;
        else if (key == array[mid_val])
        return mid_val;
    }
    return -1;
}
int main ()
{
    int arr[] = {1,  111,  151,  561,  701,  1191,  4501,  9981,  9991,  11191};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(n, arr, 11191);
    (index== -1)? cout <<"The entered element is not found."<<endl:cout <<"Required index = "<<index<<endl;   
    return 0;
}