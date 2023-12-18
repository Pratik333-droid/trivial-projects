#include <iostream>

#include <cstring>
using namespace std;

class Department 
{
    private:
    int id;
    char* name;
    static int count;

    public:
    Department (int departid, const char* departname)
    {
        cout <<++count <<" object created in address "<<this <<endl;
        id = departid;

        int leng = strlen (departname);
        name = new char [leng];
        strcpy (name, departname);

        cout <<"Department name = "<<name<<endl;
        cout <<"Department id = "<<id <<endl;
        
    }

    ~Department ()
    {
        cout <<" object "<< count-- << " at address " <<this<<" destroyed "<<endl;
        delete []name;
    }
};
int Department :: count = 0;
int main ()
{
    Department d1(12, "Computer"), d2(13, "Electronics");
    Department d3(14, "Electrical");
    return 0;

}