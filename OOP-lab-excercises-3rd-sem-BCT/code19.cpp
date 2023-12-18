#include <iostream>
using namespace std;

class Date 
{
    int day,month,year;
    public:
    void setDate();
    void displayDate();
    void validityChecker ();
    class DayErr{};
    class MonErr{};
    class YrErr{};
};
void Date :: setDate ()
{
    cout <<"Enter year"<<endl;
    cin>>year;
    cout <<"Enter month"<<endl;
    cin>>month;
    cout <<"Enter day"<<endl;
    cin>>day;
}

void Date :: displayDate ()
{
    cout <<"your date is displayed below"<<endl;
    cout <<year<<"/"<<month<<"/"<<day<<endl;
}

void Date :: validityChecker ()
{
    if (year < 1900 || year > 2021)
    throw (YrErr());
    else if (month < 1 || month > 12)
    throw (MonErr());
    else if (day <1 || day > 31)
    throw (DayErr());
}

int main ()
{
    Date dat;
    try 
    {
        dat.setDate();
        dat.validityChecker();
        cout <<"Kudos!!! No exception occoured."<<endl;
        dat.displayDate();
    }
   
    catch (Date :: YrErr)
    {
        cout <<"Invalid year"<<endl;
    }
    catch (Date :: MonErr)
    {
        cout <<"Invalid month"<<endl;
    }

    catch (Date :: DayErr)
    {
        cout <<"Invalid day"<<endl;
    }
    return 0;
}