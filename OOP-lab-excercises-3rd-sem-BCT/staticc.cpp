#include <iostream>
#include <cstring>
using namespace std;


class Cricketers 
{
    char name[10];
    int runs, wickets;
    static int count;
    public:
    static void counter();
    Cricketers()
    {
        count+=1;
        cout <<"total no of objects = "<<count <<endl;
    }
    Cricketers (const char* naam, int rns, int wkts)
    {
        count+=1;
        cout <<" total no of objects = "<<count<<endl;
        strcpy (name, naam);
        runs = rns;
        wickets = wkts;
    }
};

int Cricketers :: count = 0; 
void Cricketers :: counter ()
{
    cout <<"The total number of objects created so far = "<<count<<endl;
    // runs = 40;
}
int main ()
{
    Cricketers cric1("Warner", 2304, 0), cric2 ("Stokes", 1104, 45), cric3;
    Cricketers :: counter();
    // cric1.counter();
    // cout <<Cricketers:: count<<endl;
    return 0;
}