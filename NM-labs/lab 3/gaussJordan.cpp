#include <iostream>
#include <cmath>
using namespace std;
// #define n 3
int main()
{
    int n;
    bool no_solution = 0;
    cout << "Enter the size of nxn square matrix" << endl;
    cin >> n;
    float matrix[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << "Enter the value of a[" << i << "][" << j << "]" << endl;
            cin >> matrix[i][j];
        }
    }
    cout << "The entered matrix is" <<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            // cout <<"Enter the value of a["<<i<<"]["<<j<<"]"<<endl;
            // cin>>matrix[i][j];
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (fabs(matrix[i][i]) < 0.001)
                {
                    cout <<"The given system of equations have no unique solution."<<endl;
                    no_solution = 1;
                    break;
                }
                float div = matrix[j][i] / matrix[i][i];
                // cout <<"div = "<<div<<endl;
                for (int k = 0; k < n + 1; k++)
                {
                    // cout <<matrix [j][k]<<endl;
                    // cout <<matrix [i][k]<<endl;
                    // cout <<matrix [i][i]<<endl;
                    // cout <<matrix [j][i]<<endl;
                    matrix[j][k] = matrix[j][k] - div * matrix[i][k];
                    // cout << "matrix["<<j<<"]["<<k<<"] =" <<matrix[j][k]<<"  ";
                    // cout <<endl<<endl;
                }
                cout << endl;
            }
        }
        if (no_solution == 1)
        break;
    }
    if (no_solution ==1)
    return 0;
    cout << "The diagonal matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            // cout <<"Enter the value of a["<<i<<"]["<<j<<"]"<<endl;
            // cin>>matrix[i][j];
            cout << round(matrix[i][j]) << "     ";
            // round ()
        }
        cout << endl;
    }
    // for (int i =0; i<n; i++)
    // {
    //     if (fabs(matrix[i][i]) < 0.001)
    //     {
    //         cout <<"The given system of equations have no unique solution."<<endl;
    //         no_solution = 1;
    //         break;
    //     }
    // }
    if (no_solution ==1)
    return 0;

    cout << "The solutions are " << endl;
    for (int i = 0; i < n; i++)
    {
        matrix[i][n] /= matrix[i][i];
        cout << matrix[i][n] << endl;
    }

    return 0;
}