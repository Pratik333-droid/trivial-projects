#include <iostream>
#include <cstring>
using namespace std;
// evaluating a postfix operator
class Stack
{
    
    public:
    int top = 0;
    int array[10];
    bool isOperator(char);
    void push(int);
    void pop();

};

void Stack :: pop ()
{
    top-=1;
}
void Stack :: push(int data)
{
    array[top++] = data;
}
bool Stack :: isOperator(char cha)
{
    return (cha=='+' || cha == '-' || cha == '*' || cha == '/' || cha== '^');
}
int main ()
{
    Stack stack;
    string st;
    cout <<"Enter a string"<<endl;
    cin>>st;
    int length = st.size();
    int value;
    for (int i=0; i<length; i++)
    {
        if (stack.isOperator(st[i]) == false)
        {
            stack.push(st[i] - '0');
        }
        else
        {
            if (st[i] == '+')
            {
                value = stack.array[stack.top - 2] + stack.array[stack.top-1];
                stack.pop();
                stack.pop();
                stack.push(value);
            }
            if (st[i] == '-')
            {
                value = stack.array[stack.top - 2] - stack.array[stack.top-1];
                stack.pop();
                stack.pop();
                stack.push(value);                
            }
            if (st[i] == '*')
            {
                value = stack.array[stack.top - 2] * stack.array[stack.top-1];
                stack.pop();
                stack.pop();
                stack.push(value);              
            }
            if (st[i] == '/')
            {
                value = stack.array[stack.top - 2] / stack.array[stack.top-1];
                stack.pop();
                stack.pop();
                stack.push(value);               
            }
            if (st[i] == '^')
            {
                value = stack.array[stack.top - 2] ^ stack.array[stack.top-1];
                stack.pop();
                stack.pop();
                stack.push(value);               
            }
        }
    }
    cout <<"The result is "<<stack.array[0]<<endl;

    return 0;
}