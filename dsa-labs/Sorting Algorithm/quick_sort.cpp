#include <iostream>
using namespace std;
const int len = 6;

void display(int array[])
{
    cout <<"The elements of the array are:"<<endl;
    for (int i = 0; i<len; i++)
    cout <<array[i]<<"  ";
    cout <<endl;
}
void swap (int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp; 
}
int partition(int array[], int low, int high)
{
    int pivot = array[low]; //the first element of my list is the pivot element
    int pvt_index = low; //pvt_index holds the original index of my pivot element
    while (low< high)
    {
        
        while(array[low] <= pivot && low < len-1)
        {
            low++; //moves right until the elements in the array are less than the pivot element 
        }
        while (array[high] > pivot && high >0)
        {
            high--; //moves left until the elements in the array are greater than the pivot element
        }
        if (high < low) 
        break;
        // cout <<"gotta exchange "<<array[low]<<" and "<<array[high]<<endl;
        swap (&array[low], &array[high]);
        // display(array);
        // cout <<"low = "<<low <<" and high = "<<high<<endl;
        

    }
    swap (&array[pvt_index], &array[high]);
    return (high);
}
void quickSort(int array[], int low, int high)
{
    cout <<"low = "<<low <<" and high = "<<high<<endl;
    int pivot_index = partition(array, low, high); //returns the true/final index of the pivot element  
    cout <<"The pivot element is "<<array[pivot_index]<<" and the corresponding pivot index is "<<pivot_index<<endl;
    display(array);
    if (high - low < 1) //to my knowledge this part of code should never be executed. high - low ought not to be less than 1
    return;
    if (pivot_index - low > 1) //sort only if there are more than 1 elements to the left of pivot element
    quickSort(array, low, pivot_index-1);
    if (high - pivot_index > 1) //sort only if there are more than 1 elements to the right of pivot element
    quickSort(array, pivot_index+1, high);

}
int main ()
{
    int arr[len]= {10,7,1,9,8,4};
    cout <<"Before implementation:"<<endl;
    display(arr);
    quickSort(arr,0,len-1);
    cout <<"After implementation:"<<endl;
    display(arr);
    return 0;
}