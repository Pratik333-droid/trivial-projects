//A program to demonstrate binary search using recursive approach

#include <iostream>
using namespace std;

int binarySearch (int lower, int upper, int array[], int key)
{
    if (lower <= upper)
    {
        int mid_val = (upper + lower)/2;
        if (array[mid_val] > key)
        return binarySearch(lower, mid_val-1, array, key);
        else if (array[mid_val] < key)
        return binarySearch (mid_val+1, upper, array, key);
        else
        return mid_val;
    }
    return -1;
}
int main ()
{
    int arr[] = {1,  111,  151,  561,  701,  1191,  4501,  9981,  9991,  11191};
    int n = sizeof (arr)/sizeof (arr[0]);
    int index = binarySearch(0, n-1, arr, 1191);
    (index==-1)?cout <<"The entered data is not available in the given array."<<endl:cout <<"Index = "<<index<<endl;
    return 0;
}