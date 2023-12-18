// A program to demonstrate the implementation of radix sort

#include <iostream>
#include <cmath>
#define garbage -11111
using namespace std;
const int arr_size = 10;

void displayArray(int num[])
{
    for (int i = 0; i<arr_size; i++)
    cout <<num[i]<<",  ";
    cout <<endl;
}

int returnMaxDigit(int arr[])
{
    int digits[arr_size], temp, n, max_digit;
    for (int i = 0; i< arr_size; i++)
    {
        temp = arr[i];
        n = 0;
        while (temp!=0)
        {
            temp=abs(temp/10);
            n++; // calculates the number of digits of every number.
        }
        digits[i] = n; //stores the number of digits of every number in an array
    }
    max_digit = digits[0];
    for (int i = 0; i<arr_size; i++)
    {
        if (digits[i]>max_digit)
        max_digit = digits[i]; // finds the maximum digits
        
    }
    cout<<endl;
    return max_digit;
}

void initializeArray(int arr[arr_size][arr_size])
{
    for (int i =0; i<arr_size; i++)
    {
        for (int j =0; j<arr_size; j++)
        {
            arr[i][j] = garbage;
        }
    }
}
void radixSort(int num[arr_size], int max)
{
    int base, pos, iter, counter, array[arr_size][arr_size], div, power;
    for (int j = 1; j<=max; j++)
    {
        initializeArray(array); //each time the array has to be initialized. 
        power = j-1;
        div = pow(10, power); //pow(10,2 ) computed to be 99 for some reason. So was compelled to do this.
        if (div%9 == 0)
        div+=1;
        // cout <<"for j = "<<j<<" div = "<<div<<endl;
        counter=-1; //this keeps track of index in array where sorted element after each pass is stored
        for (int i =0; i<arr_size; i++)
        {
            
            pos = 0;
            base = (num[i]/div)% 10; // this calculates place value on each pass. for 1st pass place value = 1, for 2nd pass, place value = 10
            // cout <<"num["<<i<<"] = "<<num[i]<<" and base = "<<base<<endl;
            while (array[base][pos]!=garbage)
            {
                pos++;
            }
            array[base][pos] = num[i];
            // cout <<"array["<<base<<"]["<<pos<<"] = "<<num[i]<<endl;

        }
        for (int i = 0; i<arr_size; i++) //now that, one pass is completed so the sorted data (for a given place value)
        {                                // is to be stored in the original array by overriding it.
            iter = 0;
            if (array[i][iter] == garbage)
            continue;
            else
            {
                while(array[i][iter]!= garbage)
                {
                    num[++counter] = array[i][iter];
                    iter++;
                }
            }
        }
        displayArray(num);
        cout <<endl<<endl<<endl;
    }
    displayArray(num);
}
int main()
{
    
    int num[arr_size] = {151,701,11191,01,561,9981,4501,9991,1191,111};
    // int num[arr_size] = {40,59,1,0,20,8,19,73,311,61};
    int max = returnMaxDigit(num);
    displayArray(num);
    radixSort(num, max);
    return 0;
}