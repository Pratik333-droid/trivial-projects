// A program to demonstrate bubble sorting

#include <iostream>
const int arr_size = 10;
using namespace std;

void swap (int num[], int i, int j)
{
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}
void sortAscending(int num[])
{
    for (int i = 0; i<arr_size-1; i++)
    {
        for (int j = i+1; j<arr_size; j++)
        {
            if (num[i]>num[j])
            {
                swap (num, i, j);
            }
        }
    }
}
void sortDescending(int num[])
{
    for (int i = 0; i<arr_size-1; i++)
    {
        for (int j = i+1; j<arr_size; j++)
        {
            if (num[i]<num[j])
            {
                swap (num, i, j);
            }
        }
    }   
}

void displayArray(int num[])
{
    for (int i = 0; i<arr_size; i++)
    cout <<num[i]<<"  ";
    cout <<endl;
}
int main()
{
    int num[arr_size] = {5,7,-19,0,56,998,45,-99,-119,1};
    cout <<"The original array is "<<endl;
    displayArray(num);
    sortAscending(num);
    cout <<"The elements of the array in ascending order are:"<<endl;
    displayArray(num);
    sortDescending(num);
    cout <<"The elements of the array in descending order are:"<<endl;
    displayArray(num);
    return 0;
}