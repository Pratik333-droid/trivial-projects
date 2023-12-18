#include <cstring>
#include <iostream>
using namespace std;

class JoinString
{
    char* strng;
    int leng;
    public:
    JoinString(){}
    JoinString(const char *demostr)
    {
        leng = strlen(demostr);
        strng = new char [leng];
        strcpy (strng,demostr);
        cout <<"strng = "<<strng<<endl;
    }

    friend void joinStrings (JoinString, JoinString);
};

void joinStrings (JoinString j1, JoinString j2)
{
    int totleng= j1.leng + j2.leng;
    char *joinedstring = new char [totleng];
    strcpy(joinedstring, j1.strng);
    strcat (joinedstring, j2.strng);
    cout <<j1.strng <<" + "<<j2.strng<<" = "<<joinedstring<<endl;
    delete []joinedstring;
    delete [] j1.strng;
    delete [] j2.strng;
}

int main ()
{
    JoinString jf("Paras"), js("Khadka");
    joinStrings (jf, js);

    return 0;
}