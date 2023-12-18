#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    
    public:
    virtual void displayData () = 0;
};

class Engineering : public Student
{
    string name;
    int age, roll_no;
    public:
    void getData();
    void displayData();
};

void Engineering :: getData ()
{
    cout <<"Enter name"<<endl;
    cin>> name;
    cout <<"Enter age"<<endl;
    cin >>age;
    cout <<"Enter roll no (integer)"<<endl;
    cin >> roll_no;
}

void Engineering :: displayData()
{
    cout <<"name = "<<name<<endl;
    cout <<"age = "<<age<<endl;
    cout <<"roll_no = "<<roll_no<<endl;
}

class Medical : public Engineering
{
    string name;
    int age, roll_no;
    public:
    void getData();
    void displayData();
    
};
void Medical :: getData ()
{
    cout <<"Enter name"<<endl;
    cin>> name;
    cout <<"Enter age"<<endl;
    cin >>age;
    cout <<"Enter roll no (integer)"<<endl;
    cin >> roll_no;
}

void Medical :: displayData()
{
    cout <<"name = "<<name<<endl;
    cout <<"age = "<<age<<endl;
    cout <<"roll_no = "<<roll_no<<endl;
}

int main ()
{
    Student *stu;
    Medical med;
    Engineering eng;
    stu = &med;
    cout <<"Enter details for medical "<<endl;
    med.getData();
    cout <<"Enter details for engineering"<<endl;
    eng.getData();
    cout <<"Displaying the medical data."<<endl;
    stu->displayData();
    stu = &eng;
    cout <<"Displaying the engineering data"<<endl;
    stu->displayData();
    return 0;
    
}

