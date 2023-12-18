#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
    int n;
    cout <<"Enter the no of unknowns"<<endl;
    cin>>n;
    float matrix[n][n+1], div;
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n+1; j++)
        {
            cout <<"Enter the element a["<<i<<"]["<<j<<"]"<<endl;
            cin>>matrix[i][j];
        }
    }
    for (int i =0; i<n-1; i++)
    {
        for (int j =i+1; j<n; j++)
        {
            if (i!=j)
            {
                div = matrix[j][i]/matrix[i][i];
                // cout <<"div = "<<div<<endl;
                for (int k =0; k<n+1; k++)
                {
                    // cout<< "a["<<j<<"]["<<k<<"] = "<<matrix[j][k]<<" - "<<div <<" * "<<matrix[i][k]<<endl;

                    matrix[j][k] = matrix[j][k] - div * matrix[i][k];
                    // cout <<setw(10)<<matrix[j][k];
                }
                
            }
            // cout <<endl;

        }
        
    }
    cout <<"The upper triangular form of the matrix is "<<endl;
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n+1; j++)
        {
            // cout <<"Enter the element a["<<i<<"]["<<j<<"]"<<endl;
            // cin>>matrix[i][j];
            cout <<setw(20)<<matrix[i][j];
        }
        cout <<endl;
    }
    int zeroes = 0;
    int inconsistent = 0;
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            if (matrix[i][j] == 0)
            zeroes+=1;
            
        }
        if (zeroes==n)
        {
            inconsistent = 1;
            cout <<"No unique solution is possible for the given system of equations."<<endl;
            break;
        }
        else
        zeroes = 0;
        
    }
    float solutions[n];
    if (inconsistent == 0)
    {
        solutions [n-1] = matrix[n-1][n]/matrix[n-1][n-1];
        for (int i =n-2; i>=0; i--)
        {
            float sum = 0;
            for (int j =n-1; j>i; j--)
            {
                sum += matrix[i][j]* solutions[j];
            }
            solutions[i] = (matrix[i][n] - sum) / matrix[i][i];
        }

        cout <<"The solutions are "<<endl;
        for (int i =0; i<n; i++)
        cout <<solutions[i]<<" ";
        // cout <<round(solutions[i])<<" ";

    }

    return 0;
}