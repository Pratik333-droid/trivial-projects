#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void displayMatrix (float mat[5][10], int n)
{
    for (int i =0; i<n; i++)
    {
        for (int j=n; j< 2*n; j++)
        {
            cout <<setw(20)<<mat[i][j];
        }
        cout <<endl;
    }
}
int main ()
{
    float matrix [5][10];
    int n;
    cout <<"Enter the number of unknowns."<<endl;
    cin>>n;
    cout <<"Enter the elements of the matrix."<<endl;
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            // cout <<"Enter the value of element a["<<i<<"]["<<j<<"]"<<endl;
            cin>>matrix[i][j];
        }
        
    }
    for (int i =0; i<n; i++)
    {
        for (int j =n; j<2*n; j++)
        {
            if (i == (j-n))
            matrix[i][j] = 1;
            else
            matrix[i][j] = 0;
        }
        
    }
    cout <<endl;
    for (int i =0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            float sum =0;
            if (i!=j)
            {
                
                if (fabs(matrix[i][i])< 0.001)
                {
                    cout <<"Can't compute inverse."<<endl;
                    exit(1);
                }
                float denominator = matrix[j][i]/matrix[i][i];
                for (int k =0; k<2*n; k++)
                {
                    // cout <<"matrix["<<j<<"]["<<k<<"]"<<" = "<< matrix[j][k] <<" - " << matrix[j][i]<<" * "<<matrix[i][k]<<" / "<<matrix[i][i]<<endl;
                    matrix[j][k] = matrix[j][k] - denominator*matrix[i][k];
                    if (fabs(matrix[j][k])<0.0001)
                    matrix[j][k] = 0;
                    
                }
            }
        }
    }

    cout <<endl;
    for (int i =0; i<n; i++)
    {
        for (int j=n; j< 2*n; j++)
        {
            // cout <<setw(20)<<matrix[i][j];
            matrix[i][j]/=matrix[i][i];

        }
        cout <<endl;
    }

    cout <<"The required inverse of the entered matrix is."<<endl;
    displayMatrix (matrix, n);
    return 0;
}
