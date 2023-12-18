#include <iostream>
using namespace std;

void printArr(int arr[],int size){
    int i;
    for (i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap (int *a, int *b)
{
    int temp = *a;
    a= b;
    b = &temp;
}
void shellSort(int arr[], int n)
{
    for (int gap = n/2; gap>0; gap/=2)
    {
        for (int i = gap; i<n; i++)
        {
            int j = i - gap;
            if (arr[i]<arr[j])
            {
                swap(arr[i], arr[j]);
                if (j-gap >=0 && arr[j]< arr[j-gap])
                swap (arr[j], arr[j-gap]);
                
            }
        }
    }
}

int main()
{
    int arr[]={5,7,-19,0,56,998,45,-99,-119,1}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    cout <<"Before sorting:"<<endl;
    printArr(arr,n);
    shellSort(arr,n);
    cout <<"After sorting:"<<endl;
    printArr(arr,n);
    return 0;
}