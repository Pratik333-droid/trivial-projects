#include <iostream>
#include <cstring>
using namespace std;

class Person 
{
    char name[20];
    int age;
    public:
    Person (const char* nam, int ag)
    {
        int leng = strlen(nam);
        
        strcpy (name, nam);
        age = ag;
    }


};

class Student : public Person
{


};