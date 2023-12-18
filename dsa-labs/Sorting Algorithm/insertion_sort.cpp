//A program to demonstrate insertion sorting

#include <iostream>
using namespace std;
const int arr_size = 10;

void swap (int num[], int i, int j)
{
    int hold = num[i];
    for (int iter = i; iter>j; iter--)
    {
        num[iter] = num[iter-1];
    }
    num[j] = hold;
}

void sortAscending(int num[])
{
    for (int i = 1; i<arr_size; i++)
    {
        for (int j = 0 ; j<i; j++)
        {
            if (num[i]<num[j])
            {
                swap(num, i, j);
            }
        }
    }
}
void sortDescending(int num[])
{
    for (int i = 1; i<arr_size; i++)
    {
        for (int j = 0 ; j<i; j++)
        {
            if (num[i]>num[j])
            {
                swap(num, i, j);
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
    cout <<"The original array is:"<<endl;
    displayArray(num);
    sortAscending(num);
    cout <<"The elements of the array in ascending order is:"<<endl;
    displayArray(num);
    sortDescending(num);
    cout <<"The elements of the array in descending order is:"<<endl;
    displayArray(num);
    return 0;
}