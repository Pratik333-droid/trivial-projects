#include <iostream>
using namespace std;
//program to implement selection sort
const int arr_size = 10;

void swap(int num[], int a, int b)
{
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}
void displayArray(int num[])
{
    for (int i = 0; i<arr_size; i++)
    cout <<num[i]<<"  ";
    cout <<endl;
}
void sortAscending (int num[])
{
    
    int k = 1;
    int largest_index, largest;
    for (int j = 0; j<arr_size-1; j++)
    {   
        largest = num[0];
        largest_index = 0;

        for (int i = 0; i<=arr_size - k; i++)
        {
            if (num[i]>largest)
            {   
                largest = num[i];
                largest_index = i;
            }
        }
        
        swap(num, largest_index, arr_size-k);
        k++;
    }
}

void sortDescending (int num[])
{
    
    int k = 1;
    int largest_index, largest;
    for (int j = 0; j<arr_size-1; j++)
    {   
        largest = num[k-1];
        largest_index = k-1;

        for (int i = k-1; i<arr_size; i++)
        {
            if (num[i]>largest)
            {   
                largest = num[i];
                largest_index = i;
            }
        }
        
        swap(num, largest_index, k-1);
        k++;
    }
}
int main ()
{

    int num[arr_size] = {5,7,-19,0,56,998,45,-99,-119,1};
    cout <<"The original array is "<<endl;
    displayArray(num);
    sortAscending(num);
    cout <<"The elements of array in ascending order is:"<<endl;
    displayArray(num);
    sortDescending(num);
    cout <<"The elements of array in descending order is:"<<endl;
    displayArray(num);
    return 0;

}