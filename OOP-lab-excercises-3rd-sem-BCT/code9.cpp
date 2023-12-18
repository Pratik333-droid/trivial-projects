#include <iostream>

using namespace std;
// class Gram {};
const float TOLA_TO_GRAM = 11.664;
class Tola 
{
    float wt_tola;
    public:
    void setWeightTola ();
    float getWeightTola ();
    // friend void operator = (Tola, Gram);
};
void Tola :: setWeightTola ()
{
    cout <<"Enter the weight of gold in tola to convert it into gram."<<endl;
    cin>>wt_tola;
}
float Tola :: getWeightTola()
{
    // cout <<"weight of gold = "<<wt_tola<<" tola "<<endl;
    return wt_tola;
}

class Gram
{
    float wt_gram;
    public:
    void operator = (Tola);
    float displayGram();

};

void Gram :: operator = (Tola tola_obj)
{
    wt_gram = tola_obj.getWeightTola()* TOLA_TO_GRAM;
}

float Gram :: displayGram()
{
    return wt_gram;
}

int main ()
{
    Tola obj_tol;
    Gram obj_gram;
    obj_tol.setWeightTola();
    obj_gram = obj_tol;
    cout <<obj_tol.getWeightTola()<<" tola = "<<obj_gram.displayGram()<<" grams. "<<endl;
    return 0;
}