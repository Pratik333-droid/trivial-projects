#include <iostream>
using namespace std;

class Date 
{
    int year, month, day;
    public:
    void getDate();
    void displayDate();
    friend int operator - (Date, Date);
    friend Date operator + (Date, Date);

};

void Date:: getDate ()
{
    cout <<"Enter freaking day"<<endl;
    cin >> day;
    cout <<"Enter freaking month"<<endl;
    cin >>month;
    cout <<"Enter freaking year"<<endl;
    cin >>year;

}

void Date :: displayDate ()
{
    cout <<year<<"/"<<month<<"/"<<day<<endl;

}

int operator - (Date d1, Date d2)
{
    int difference;
    difference = d1.day - d2.day + (d1.month - d2.month)*30 + (d1.year-d2.year)*365;
    return (difference);
}

Date operator + (Date d3, Date d4)
{
    Date temp;
    temp.day = d3.day + d4.day;
    temp.month = d3.month + d4.month;
    temp.year = d3.year + d4.year;
    if (temp.day >= 30)
    {
        temp.month += temp.day/30;
        temp.day%= 30;

    }
    if (temp.month > 11)
    {
        temp.year+=temp.month/12;
        temp.month%= 12;
    }
    return temp;
}

int main ()
{
    Date date1, date2, date3;
    cout <<"Enter the first date."<<endl;
    date1.getDate();
    cout <<"Enter the second date."<<endl;
    date2.getDate();
    cout <<"The dates entered are "<<endl;
    date1.displayDate();
    date2.displayDate();
    cout <<"The difference between the entered dates is "<<(date2- date1)<<" days"<<endl;
    cout <<"the added date is "<<endl;
    date3 = date1 + date2;
    date3.displayDate();
    return 0;
}