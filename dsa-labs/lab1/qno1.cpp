#include <iostream>
using namespace std;
/*
1.	Perform push and pop operations in stack
2.	Convert  : 
a.	Infix expression to postfix expression
b.	Infix expression to prefix expression
3.	Evaluate the postfix expression
4.	Check the paired parenthesis in mathematical expression
*/
const int sizee = 3;
// template <class T>
class Stack
{
    private:
    int array[sizee], top=-1;
    public:
    void push(int);
    void pop();
};
// template <typename T>
void Stack:: push(int data)
{
    if (top>= sizee-1)
    {
        cout <<"Can't push items. Stack overflow"<<endl;
    }
    else
    {
        top+=1;
        
        array[top] = data;
        cout <<array[top]<<" at position "<<top <<" has been pushed"<<endl;

    }
}
// template <typename T>
void Stack :: pop ()
{
    if (top<0)
    {
        cout <<"Can't pop items. Stack underflow"<<endl;
    }
    else
    {
        cout <<array[top]<<" at position "<<top<<" has been popped "<<endl;
        top-=1;
    }

}
// template <typename T>
int main ()
{
    Stack stack;
    // int a = 3;
    stack.push(3);
    stack.push(4);
    stack.push(3);
    stack.push(5);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
}