//wap that finds the sum and average of elements in an array using function template

#include <iostream>
using namespace std;

template <class T, class U>
void arrayFunction (T arr[], int len, U &sum, U &avg)
{
    int length = len;
    sum = avg = 0;
    
    for (int i =0; i<length; i++)
    {
        sum+=arr[i];
    }
    avg = sum/len;
}

int main ()
{
    float array[5] = {1.1,2.2,3.3,4.4,5.5};
    int len = (sizeof(array)/sizeof(array[0]));
    int summ = 0;
    int avgg = 0;
    arrayFunction (array, len, summ, avgg);
    cout <<"The sum and average of the array elements are "<<summ<<" and "<<avgg<<" respectively "<<endl;
    return 0;
}