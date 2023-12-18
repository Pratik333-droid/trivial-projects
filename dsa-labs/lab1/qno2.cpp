// 4.	Check the paired parenthesis in mathematical expression
#include <iostream>
#include <cstring>
using namespace std;
const int sizee = 5;
class Stack
{
    char paran[sizee];
    int top=-1;
    public:
    void Push(char);
    void Pop();
    void checkBalanced();
};

void Stack :: Push(char ch)
{
    
    paran[++top] = ch;
    cout <<"push top = "<<top<<endl;
}

void Stack :: Pop()
{
    top-=1;
    cout <<"pop top = "<<top<<endl;
}

void Stack :: checkBalanced ()
{
    if (top==-1)
    {
        cout <<"Balanced "<<endl;

    }
    else
    {
        cout <<"not balanced"<<endl;
        cout <<"top = "<<top<<endl;
    }
}

int main ()
{
    Stack stack;
    string stt;
    cout <<"Enter your string"<<endl;
    cin>>stt;
    // int length = sizeof(stt)/sizeof(stt[0]);
    int length = stt.size();
    for (int i=0; i<length; i++)
    {
        if (stt[i]=='[' || stt[i] == '{' || stt[i] =='(')
        {
            // paran[++top] = stt[i];
            stack.Push(stt[i]);
        }
        else if (stt[i] == ']' || stt[i] == '}' || stt[i] ==')')
        {
            stack.Pop();

        }
    }
    stack.checkBalanced();
    return 0;
}