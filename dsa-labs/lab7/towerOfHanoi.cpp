#include <iostream>
using namespace std;
void printSteps(int,int);
void toh(int num, int start, int end)
{
    if (start<1 || start > 3 || end < 1 || end > 3 || num<1 || start == end)
    {
    
        cout <<"Invalid argument."<<endl;
        return;
    }
    if (num == 1)
    {
        // cout <<"base case hit";
        printSteps(start, end);
        return;
    }
    // cout <<"."<<endl;
   int other = 6 - (start + end);
//    cout <<"other = "<<other<<endl;
   toh (num-1, start, other);
   printSteps(start, end);
   toh (num-1, other, end);
//    printSteps (other, end);
}

void printSteps (int start, int end)
{
    cout <<start<<" -> "<<end<<endl;
}
int main()
{
    toh (3,1,3);
    return 0;
}