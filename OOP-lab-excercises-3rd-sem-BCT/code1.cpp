#include <iostream>
using namespace std;

class LandMeasure 
{
    private:
    int ropani, ana, paisa, dam;
    //16 ana = 1 ropani, 4 paisa = 1 ana , 4 dam =1 paisa
    public:
    void inputData ();
    void displayData ();
    LandMeasure sumObjects (LandMeasure, LandMeasure);
};

LandMeasure LandMeasure :: sumObjects (LandMeasure l1, LandMeasure l2)
{
    LandMeasure l3;
    l3.dam = l1.dam + l2.dam;
    l3.paisa = l1.paisa + l2.paisa;
    l3.ana = l1.ana + l2.ana;
    l3.ropani = l1.ropani + l2.ropani;
    if (l3.dam >= 4)
    {
        l3.paisa+= l3.dam/4;
        l3.dam %=4;
    }
    if (l3.paisa >=4)
    {
        l3.ana+= l3.paisa/4;
        l3.paisa%=4;
    }

    if (l3.ana >= 16)
    {
        l3.ropani += l3.ana/16;
        l3.ana%=16;
    }
    return l3;
} 

void LandMeasure :: inputData ()
{
    cout <<"Enter ropani"<<endl;
    cin >>ropani;
    cout <<"Enter ana"<<endl;
    cin >>ana;
    cout <<"Enter paisa"<<endl;
    cin >>paisa;
    cout <<"Enter dam"<<endl;
    cin >>dam;
}

void LandMeasure :: displayData ()
{
    cout <<"ropani = "<<ropani<<endl;
    cout <<"ana = "<< ana<<endl;
    cout <<"paisa = "<< paisa <<endl;
    cout <<"dam = "<<dam<<endl;
}

int main ()
{
    LandMeasure land1, land2, land3;
    land1.inputData ();
    land2.inputData ();
    land3 = land3.sumObjects (land1, land2);
    land3.displayData();
    return 0;
}