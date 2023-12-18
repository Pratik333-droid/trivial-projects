#include <iostream>
#include <cmath>
#define SIZEE 5
using namespace std;


// void matrixVectorMultiply(float mat[SIZEE][SIZEE], float vect[SIZEE], int n)
// {
//     int i,j;
//     float sum;
//     for (i =0; i<n; i++)
//     {    
//         sum = 0;
//         for (j =0; j<n; j++)
//         {
//             // cin>>mat[i][j];
//             sum += mat[i][j] * vect[j];
//         }
//         vect[i] = sum;
//     }

// }
int main()
{
    int n,i,j, count =0;
    bool perfect = 0;
    float matrix[SIZEE][SIZEE], vector[SIZEE], vec[SIZEE], difference[SIZEE], large, large_lite,sum;
    cout <<"Enter the value of n, size of the square matrix."<<endl;
    cin>>n;
    cout <<"Enter the elements of the matrix."<<endl;
    for (i =0; i<n; i++)
    {    
        for (j =0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    for (i =0; i<n; i++)
    {   
        vector[i] = 0;
        for (j =0; j<n; j++)
        {
            // cin>>matrix[i][j];
            vector[i]+=matrix[i][j];
        }
    }
    for (i =0; i<n; i++)
    {
        vec[i] = 1;
    }

    while (1)
    {

        if ((count++)>10)
        break;
        for (i =0; i<n; i++)
        {

            difference[i] = fabs(vector[i]-vec[i]);
            // if (difference[i]>0.01)
            // break;

        }
        large_lite =difference[0];
        for (i=0; i<n; i++)
        {
            if (difference[i] > large_lite)
            large_lite  = difference[i];
        }
        if (large_lite<0.01)
        break;
        

        large = vector[0];
        for (j=0; j<n; j++)
        {
            if (vector[j]>large)
            large = vector[j];
            
        }
        // cout <<"large = "<<large<<endl;

        for (j=0; j<n; j++)
        {
            // if (vector[j]>large)
            // large = vector[j];
            vector[j]=vector[j]/large;
        }
        for (j=0; j<n; j++)
        {
            vec[j] = vector[j];
        }

        // matrixVectorMultiply(matrix, vector, n);

        for (i =0; i<n; i++)
        {    
            sum = 0;
            for (j =0; j<n; j++)
            {
                // cin>>mat[i][j];
                sum += matrix[i][j] * vec[j];
            }
            vector[i] = sum;
        }
        large = vector[0];
        for (j=0; j<n; j++)
        {
            if (vector[j]>large)
            large = vector[j];
            
        }
        for (j=0; j<n; j++)
        {
            // if (vector[j]>large)
            // large = vector[j];
            vector[j]=vector[j]/large;
        }
        // for (i=0; i<n; i++)
        // cout <<vector[i]<<"  ";
        // cout<<endl<<"count = "<<count<<endl;


    }

    for (i=0; i<n; i++)
    cout <<vector[i]<<"  ";
    cout <<endl<<"The corresponding eigen value is "<<large<<endl;
    cout<<endl<<"count = "<<count<<endl;

    return 0;
}