#include <iostream>
using namespace std;

class Time
{
    int hours, minutes, seconds;
    public:

    void timeInput ();
    void displayTime ();
    friend Time timeAdder (Time, Time);
};

void Time :: timeInput() 
{
    cout <<"Enter hours, minutes and seconds."<<endl;
    cin >> hours>> minutes>>seconds;

}

void Time :: displayTime()
{
    
    cout <<hours<<" hour "<<minutes<<" minutes "<<seconds<<" seconds "<<endl;
}
Time timeAdder (Time t1, Time t2)
{
    Time t3;
    t3.hours = t1.hours + t2.hours;
    t3.minutes = t1.minutes + t2.minutes;
    t3.seconds = t1.seconds + t2.seconds;
    if (t3.seconds >= 60)
    {
        t3.minutes +=t3.seconds/60;
        t3.seconds%=60;
    }
    if (t3.minutes >= 60)
    {
        t3.hours+=t3.minutes/60;
        t3.minutes%=60;
    }

    return t3;
}   

int main ()
{

    Time t_one, t_two, t_three;
    t_one.timeInput();
    t_two.timeInput();
    t_three = timeAdder (t_one, t_two);
    t_one.displayTime();
    t_two.displayTime();
    cout <<"On adding the above two times, we get"<<endl;
    t_three.displayTime();

}