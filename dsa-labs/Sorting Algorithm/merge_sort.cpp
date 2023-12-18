//a c++ program to implement merge sort.
#include <iostream>
using namespace std;
const int arr_size = 10;
int sorted_array[arr_size];
int no_of_merges = 0;
void displayArray(int disp_array[])
{
    cout <<"The elements of the array are:"<<endl;
    for (int i = 0; i<arr_size; i++)
    cout <<disp_array[i]<<"  ";
    cout <<endl;
}

void merge(int array[], int lwr, int mid, int upr)
{
    int iter = lwr-1;
    no_of_merges++;
    int i = lwr;
    int j = mid+1;
    while (i<=mid || j<= upr)
    {
        if (array[i] < array[j])
        {
            sorted_array[++iter] = array[i];
            // cout <<"sorted_array["<<iter<<"] = "<<array[i]<<endl;
            i++;
        }
        else if (array[i] > array[j])
        {
            sorted_array[++iter] = array[j];
            // cout <<"sorted_array["<<iter<<"] = "<<array[j]<<endl;
            j++;   
        }
        else //if two numbers are equal
        {
            sorted_array[++iter] = array[i];
            sorted_array[++iter] = array[i];
            i++;
            j++;
            // cout <<"will be surprised if this is printed."<<endl;
        }
        if (i>mid || j>upr)
        {
            if (i> mid && j<= upr)
            {
                while (j<=upr)
                {
                    sorted_array[++iter] = array[j];
                    // cout <<"sorted_array["<<iter<<"] = "<<array[j]<<endl;
                    j++;
                }
            }

            if (j> upr && i<= mid)
            {
                while (i<=mid)
                {
                    sorted_array[++iter] = array[i];
                    // cout <<"sorted_array["<<iter<<"] = "<<array[i]<<endl;
                    i++;
                }
            }        
        }

    }

    for (int k = lwr; k<=upr; k++)
    array[k] = sorted_array[k];
    // cout <<"after "<<no_of_merges<<" merges "<<" the array is as shown below:"<<endl;

}
void partition(int arr[], int lower, int upper)
{
    int middle = (upper + lower)/2;
    // cout <<"lower = "<<lower<<" middle = "<<middle<<" and upper = "<<upper<<endl;
    if (middle != lower)
    {
        partition(arr, lower, middle);
        partition(arr, middle+1, upper);
        merge(arr, lower, middle, upper);
    }
    else //if (middle == lower)
    {
        // cout<<"then:"<<endl;
        // displayArray(arr);
        if (lower!= upper)
        {
            if (arr[lower] > arr[upper])
            {
                int temp = arr[lower];
                arr[lower] = arr[upper];
                arr[upper] = temp;
            }
        }
        // cout <<"now:"<<endl;
        // displayArray(arr);
        // cout<<endl<<endl;


    }
}
int main()
{
    int num[arr_size] = {5,7,-19,0,56,998,45,-99,-119,1}; 
    cout <<"Before sorting:"<<endl;
    displayArray(num);
    partition(num, 0, arr_size-1);
    cout <<"After sorting:"<<endl;
    displayArray(num);

    // for (int i = 0; i<arr_size; i++)
    // cout <<sorted_array[i]<<"  ";
    // cout <<endl;
    return 0;
}