#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
// a.	Infix expression to postfix expression
#define sizee 20
class Stack
{
    int top = 0;
    // char array[sizee];
    bool flag_plus =0, flag_minus =0, flag_multiply =0, flag_divide =0;
    string stt="";
    char array[sizee];
    public:
    bool checkNull();
    bool isOperand(char);
    bool isParanthesis(char);
    void push(char);
    void pushOper(char);
    void popOper();
    void handlePlus();
    void handleMinus();
    void handleDivide();
    void handleMultiply();
    void handleExponent();
    bool isClosingParanthesis(char);
    void handleClosingParan1 (); //handles )
    void handleClosingParan2 (); // handles }
    void handleClosingParan3 (); // handles ]
    void displayString();
    bool isStackEmpty();
    void emptyStack();
};
bool Stack :: isStackEmpty()
{
    if (top == 0)
    return true;
    else
    return false;
}
void Stack :: emptyStack()
{
    for (int j= top-1; j>=0; j--)
    {
        // cout <<"ma yaha pani xu"<<endl;
        cout <<"arrayoper["<<j<<"]= "<<array[j]<<endl;

        push(array[j]);
    }
}
void Stack :: displayString()
{
    // string str = "";
    // for (int i=0; i<top;  i++)
    // {
    //     str+=array[i];
    // }
    cout <<stt;
    // cout <<"k xa kta kti ho"<<endl;

}
void Stack :: handleClosingParan1 ()//handles )
{
        for (int i = top-1; i>=0; i--)
        {
       
            if (array[i] == '(')
            {
                popOper();
                break;
            }
            else
            {
                push(array[i]);
                popOper();
            }
        }
}
void Stack :: handleClosingParan2 () // handles }
{
        for (int i = top-1; i>=0; i--)
        {
       
            if (array[i] == '{')
            {
                popOper();
                break;
            }
            else
            {
                push(array[i]);
                popOper();
            }
        }
}
void Stack :: handleClosingParan3 () // handles ]
{
        for (int i = top-1; i>=0; i--)
        {
       
            if (array[i] == '[')
            {
                popOper();
                break;
            }
            else
            {
                push(array[i]);
                popOper();
            }
        }
}
bool Stack :: isClosingParanthesis(char cparan)
{
    return( cparan==']' || cparan=='}' || cparan == ')');
}
void Stack :: popOper()
{
    cout <<array[top-1]<<" has been popped"<<endl;
    top-=1;
}
void Stack :: handlePlus ()
{
    if (isParanthesis(array[top-1]) == true)
    {
        pushOper('+');
    }
    else
    {
        // int j =1;
        // while (top_oper-j >=0)
        // {
        //     if (isParanthesis(arrayoper[j])== true)
        //     {
        //         pushOper('+');
                
        //         break;
        //     }
        //     else
        //     {
        //         push(arrayoper[j]);
        //         j+=1;
        //         popOper();
        //     }

        // }
        for (int i = top-1; i>=0; i--)
        {
            if (isParanthesis(array[i])== true)
            {
                pushOper('+');
                flag_plus =1;
                break;
            }
            else
            {
                push(array[i]);
                popOper();
                
            }
            // pushOper('+');
        }
        if (flag_plus == 0)
        pushOper('+');
    }
}
//handles minus sign
void Stack :: handleMinus()
{
    if (isParanthesis(array[top-1]) == true)
    {
        pushOper('-');
    }
    else
    {
        for (int i = top-1; i>=0; i--)
        {
            if (isParanthesis(array[i])== true )
            {
                pushOper('-');
                flag_minus =1;
                break;
            }
            
            else
            {
                push(array[i]);
                popOper();
            }

        }
        if (flag_minus == 0)
        pushOper('-');
        // int j =1;
        // while (top_oper-j >=0)
        // {
        //     if (isParanthesis(arrayoper[j])== true)
        //     {
        //         pushOper('-');
                
        //         break;
        //     }
        //     else
        //     {
        //         push(arrayoper[j]);
        //         j+=1;
        //         popOper();
        //     }

        // }
    }
}
void Stack :: handleMultiply ()
{
    if (isParanthesis(array[top-1]) == true)
    {
        // cout <<"I am here"<<endl;
        pushOper('*');
    }
    else
    {
        for (int i = top-1; i>=0; i--)
        {
            if (isParanthesis(array[i])== true || array[i]=='+' || array[i]=='-')
            {
                pushOper('*');
                flag_multiply = 1;
                break;
            }
            
            else
            {
                push(array[i]);
                popOper();
            }
        }
        if (flag_multiply == 0)
        pushOper('*');        // int j =1;
        // while (top_oper-j >=0)
        // {
        //     if (isParanthesis(arrayoper[j])== true || arrayoper[j]=='+' || arrayoper[j]=='-')
        //     {
        //         pushOper('*');
                
        //         break;
        //     }
        //     else
        //     {
        //         push(arrayoper[j]);
        //         j+=1;
        //         popOper();
        //     }

        // }
    }
}
void Stack :: handleDivide ()
{
    if (isParanthesis(array[top-1]) == true)
    {
        pushOper('/');
    }
    else
    {
        for (int i = top-1; i>=0; i--)
        {
            if (isParanthesis(array[i])== true || array[i]=='+' || array[i]== '-')
            {
                pushOper('/');
                flag_divide = 1;
                break;
            }
            
            else
            {
                push(array[i]);
                popOper();
            }
            
        }
        if (flag_divide == 0)
        {
            pushOper('/');

        }
        // int j =1;
        // while (top_oper-j >=0)
        // {
        //     if (isParanthesis(arrayoper[j])== true || arrayoper[j]=='+' || arrayoper[j]=='-')
        //     {
        //         pushOper('/');
                
        //         break;
        //     }
        //     else
        //     {
        //         push(arrayoper[j]);
        //         j+=1;
        //         popOper();
        //     }

        // }
        
    }
}
void Stack :: handleExponent ()
{
    // if (isParanthesis(arrayoper[top_oper-1]) == true)
    // {
    //     pushOper('^');
    // }
    // else
    // {
    //     for (int i = top_oper-1; i>=0; i--)
    //     {
    //         if (isParanthesis(arrayoper[i])== true || arrayoper[i]=='+' || arrayoper[i]=='-' || arrayoper[i] =='*' || arrayoper[i]=='/')
    //         {
    //             pushOper('^');
    //             break;
    //         }
            
    //         else
    //         {
    //             push(arrayoper[i]);
    //             popOper();
    //         }
    //     }
    // }
    pushOper('^');
}


bool Stack :: isParanthesis(char paran)
{
    return( paran =='['|| paran == '{' || paran  == '(');
}
bool Stack:: isOperand(char op)
{
    return (op == '+' || op == '-' || op == '*' || op== '/' || op == '^');
}
bool Stack :: checkNull ()
{
    if (top == 0)
    return true;
    else 
    return false;
}
void Stack :: push (char ch)
{
    // array[top++] = ch;

    stt+=ch;
    cout <<"string  = "<<stt<<endl;
}
void Stack :: pushOper(char operand)
{
    cout <<"operator "<<operand<<" has been pushed at position "<<top<<endl;
    array[top++] = operand;
}

int main ()
{
    Stack stack;
    string strng;
    cout <<"Enter the expression"<<endl;
    cin>>strng;
    int length = strng.size();
    // cout <<"The length of the entered string is "<<length<<endl;
    for (int i =0; i<length; i++)
    {
        if ((strng[i]>='a' && strng[i]<='z') || (strng[i]>='A' && strng[i]<='Z'))
        {
            stack.push(strng[i]);
        }
        else if (stack.isOperand(strng[i])== true && stack.checkNull() == true)
        {
            stack.pushOper(strng[i]);
        }
        else if (stack.isParanthesis(strng[i]) == true)
        {
            stack.pushOper(strng[i]);
        }
        else if (stack.isOperand(strng[i])== true)
        {
            if (strng[i] == '+')
            {
                stack.handlePlus();
            }
            else if (strng[i] == '-')
            {
                stack.handleMinus();
            }
            else if (strng[i] == '*')
            {
                stack.handleMultiply();
            }
            else if (strng[i] == '/')
            {
                stack.handleDivide();
            }
            else if (strng[i] == '^')
            {
                stack.handleExponent();
            }
        }

        else if (stack.isClosingParanthesis(strng[i])== true)
        {
            if (strng[i]==')')
            {
                stack.handleClosingParan1();
            }
            else if (strng[i] == '}')
            {
                stack.handleClosingParan2();
            }
            else if (strng[i] == ']')
            {
                stack.handleClosingParan3();
            }
        }


    }
    if (stack.isStackEmpty() == false)
    {
        // cout <<"here i am"<<endl;
        stack.emptyStack();
    }
    stack.displayString();
    return 0;
}