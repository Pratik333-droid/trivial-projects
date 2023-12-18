#include <iostream>

using namespace std;

class Date 
{
    int day, month, year;
    public:
    void setDate();
    void displayDate();

};

void Date :: setDate ()
{
    
        cout <<"Enter year"<<endl;
        cin>> year;
        cout <<"Enter month no"<<endl;
        cin>>month;
        cout <<"Enter day of birth"<<endl;
        cin >>day;
        if (year > 2021 || year < 1900)
        throw 0;
        else if (month <1 || month > 12)
        throw (1.1f);
        else if (day <1 || day >31)
        throw "Error";
    

}

void Date :: displayDate ()
{
    cout <<"The date is displayed below"<<endl;
    cout <<year <<"/"<<month<<"/"<<day<<endl;
}

int main ()
{
    Date dat;
    try 
    {
        dat.setDate();
        dat.displayDate();
    }
    catch (int i)
    {
        cout <<"Error in year"<<endl;
    }
    catch (float f)
    {
        cout <<"Error in month"<<endl;
    }
    catch (const char* cha)
    {
        cout <<"Error in day"<<endl;
    }

    
    
    return 0;
}