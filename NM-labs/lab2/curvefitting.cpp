#include <iostream>
#include <cmath>
using namespace std;
const int n = 5;
int main ()
{
    // y = a + bx
    float sum_x2=0, sum_x=0, sum_y=0, sum_xy=0, a, b;
    float numlist[n][n];
    for (int i =0; i<n; i++)
    {
        cout <<"Enter the x value"<<endl;
        cin>>numlist[i][0];
        cout <<"Enter the y value"<<endl;
        cin>>numlist[i][1];

    }
    for (int i =0; i<n; i++)
    {
        sum_x2+= pow(numlist[i][0],2);
        sum_x+= numlist[i][0];
        sum_y+= numlist[i][1];
        sum_xy+= numlist[i][0]*numlist[i][1];
    }

    a = (sum_x2* sum_y - sum_x* sum_xy)/ (n* sum_x2 - pow(sum_x,2));
    b = (sum_x * sum_y - n* sum_xy)/(pow(sum_x,2)- n*sum_x2);

    cout <<"a = "<<a<<" and b = "<<b<<endl;

    

}