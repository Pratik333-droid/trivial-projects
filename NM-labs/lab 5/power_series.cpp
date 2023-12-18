#include <iostream>
#include <cmath>
#define sizee 5
using namespace std;

void inputMatrix (float mat[sizee][sizee], float vec[sizee], int num)
{
    cout <<"Enter the elements of the matrix."<<endl;
    for (int i =0; i<num; i++)
    {
        for (int j =0; j<num; j++)
        {
            cin>>mat[i][j];
        }
        vec[i] = 1;
    }
}

void multiplyMatrixVector (float mat[sizee][sizee], float vec[sizee], int num)
{
    float temp_vec[sizee], sum;
    for (int i =0; i<num; i++)
    {
        sum = 0;
        for (int j=0; j<num; j++)
        {
            sum+=mat[i][j]*vec[j];
        }
        temp_vec[i] = sum;
    }
    for (int i=0; i<num; i++)
    vec[i] = temp_vec[i];
}

float calcError(float vect_old[sizee], float vect_new[sizee], int num)
{
    float maxerror = 0;
    float difference[sizee];
    for (int i=0; i<num; i++)
    {
        difference[i] = fabs(vect_new[i]- vect_old[i]);
        if (difference[i]>maxerror)
        maxerror = difference[i];
    }
    return maxerror;
    
}

void display(float vect[sizee], int num)
{
    cout <<"The eigen vectors are:"<<endl;
    for (int i =0; i<num; i++)
    cout <<vect[i]<<"   ";
    cout <<endl;
    
}
int main ()
{
    float matrix[sizee][sizee], vect[sizee], prev_vect[sizee], error, large;
    int n, count=0;
    cout <<"Enter the value of n"<<endl;
    cin>>n;
    inputMatrix(matrix, vect, n);
    do
    {
      
        count++;
        multiplyMatrixVector(matrix, vect, n);
        
        large = vect[0];
        for (int i =0; i<n; i++)
        {
            if (fabs(vect[i])>large)
            large = vect[i];
        }
        for (int i=0; i<n; i++)
        vect[i]/=large;
        error = calcError(prev_vect, vect, n);
        for (int i =0; i<n; i++)
        {
            prev_vect[i] = vect[i];
        }
        
    } while (error>0.005 && count<50);
    
    display(vect, n);
    cout <<"error = "<<error<<" and count = "<<count<<endl;
    cout <<"The corresponding eigen value is "<<large<<endl;

    return 0;
}