#include <iostream>

using namespace std;

//wap to overload the unary operator and the + operator to add matrices

class Matrix
{
    int mat[3][3];
    public:
    void displayValues ();
    void setValues();
    Matrix operator + (Matrix);
};

void Matrix :: setValues ()
{
    for (int i =0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout <<"enter the value of a["<<i<<"]["<<j<<"]"<<endl;
            cin >> mat[i][j];
        }
        
    }
}

void Matrix :: displayValues ()
{
    for (int i =0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout <<mat[i][j]<<"     ";
           
        }
        cout <<endl;
    }  
}

Matrix Matrix :: operator+ (Matrix matty)
{
    Matrix temp;
    for (int i =0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            temp.mat[i][j] = mat[i][j] + matty.mat[i][j];
           
        }
        
    } 
    return temp; 
}

int main ()
{
    Matrix matrix1, matrix2, matrix3;
    matrix1.setValues();
    matrix2.setValues();
    cout <<"The entered matrices are as follows"<<endl;
    matrix1.displayValues();
    matrix2.displayValues();
    matrix3 = matrix1 + matrix2;
    cout <<"The sum of the entered matrices is "<<endl;
    matrix3.displayValues();
    return 0;

}

