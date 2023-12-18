#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
// a.	Infix expression to postfix expression
#define sizee 20
class Stack
{
    int top = 0, top2=0;
    bool flag_plus =0, flag_minus =0, flag_multiply =0, flag_divide =0;
    bool flag_plus2 =0, flag_minus2 =0, flag_multiply2 =0, flag_divide2 =0;

    string stt="";
    string stt2 = "";
    char array[sizee];
    char array2[sizee];
    public:
    bool checkNull();
    bool isOperand(char);
    bool isParanthesis(char);
    bool isClosingParanthesis(char);
    bool isStackEmpty();
    void push(char);
    void pushOper(char);
    void popOper();
    void handlePlus();
    void handleMinus();
    void handleDivide();
    void handleMultiply();
    void handleExponent();
    void handleClosingParan1 (); //handles )
    void handleClosingParan2 (); // handles }
    void handleClosingParan3 (); // handles ]
    void emptyStack();

    bool isParanthesis2(char);
    bool isClosingParanthesis2(char);
    bool checkNull2();
    bool isStackEmpty2();
    void push2(char);
    void pushOper2(char);
    void popOper2();
    void handlePlus2();
    void handleMinus2();
    void handleDivide2();
    void handleMultiply2();
    void handleExponent2();
    void handleClosingParan1ii (); //handles )
    void handleClosingParan2ii (); // handles }
    void handleClosingParan3ii (); // handles ]
    void emptyStack2();
    void displayString();
    string reverseString(string);

};
bool Stack :: isStackEmpty()
{
    if (top == 0)
    return true;
    else
    return false;
}

bool Stack :: isStackEmpty2()
{
    if (top2 == 0)
    return true;
    else
    return false;
}
void Stack :: emptyStack()
{
    for (int j= top-1; j>=0; j--)
    {
        // cout <<"arrayoper["<<j<<"]= "<<array[j]<<endl;

        push(array[j]);
    }
}
void Stack :: emptyStack2()
{
    for (int j= top2-1; j>=0; j--)
    {
        // cout <<"arrayoper["<<j<<"]= "<<array[j]<<endl;

        push2(array2[j]);
    }
}
void Stack :: displayString()
{
    stt2 = reverseString(stt2);

    cout <<"The postfix of the given string is "<<stt<<endl;
    cout <<"The prefix of the given string is "<<stt2<<endl;

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
void Stack :: handleClosingParan1ii ()//handles )
{
        for (int i = top2-1; i>=0; i--)
        {
       
            if (array2[i] == ')')
            {
                popOper2();
                break;
            }
            else
            {
                push2(array2[i]);
                popOper2();
            }
        }
}
void Stack :: handleClosingParan2ii () // handles }
{
        for (int i = top2-1; i>=0; i--)
        {
       
            if (array2[i] == '}')
            {
                popOper2();
                break;
            }
            else
            {
                push2(array2[i]);
                popOper2();
            }
        }
}
void Stack :: handleClosingParan3ii () // handles ]
{
        for (int i = top2-1; i>=0; i--)
        {
       
            if (array2[i] == ']')
            {
                popOper2();
                break;
            }
            else
            {
                push2(array[i]);
                popOper2();
            }
        }
}
bool Stack :: isClosingParanthesis(char cparan)
{
    return( cparan==']' || cparan=='}' || cparan == ')');
}

void Stack :: popOper()
{
    // cout <<array[top-1]<<" has been popped"<<endl;
    top-=1;
}

void Stack :: popOper2()
{
    cout <<array2[top2-1]<<" has been popped"<<endl;
    top2-=1;
}
void Stack :: handlePlus ()
{
    if (isParanthesis(array[top-1]) == true)
    {
        pushOper('+');
    }
    else
    {
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
    }
}
void Stack :: handleMultiply ()
{
    if (isParanthesis(array[top-1]) == true)
    {
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
        pushOper('*'); 
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
        
    }
}
void Stack :: handleExponent ()
{

    pushOper('^');
}
void Stack :: handlePlus2 ()
{
    if (isClosingParanthesis(array2[top2-1]) == true)
    {
        pushOper2('+');
    }
    else
    {
        for (int i = top2-1; i>=0; i--)
        {
            if (isClosingParanthesis(array2[i])== true || array2[i] == '+' || array2[i] =='-')
            {
                pushOper2('+');
                flag_plus2 =1;
                break;
            }
            else
            {
                push2(array2[i]);
                popOper2();
                
            }
        }
        if (flag_plus2 == 0)
        pushOper2('+');
    }
}
//handles minus sign
void Stack :: handleMinus2()
{
    if (isClosingParanthesis(array2[top2-1]) == true )
    {
        pushOper2('-');
    }
    else
    {
        for (int i = top2-1; i>=0; i--)
        {
            if (isClosingParanthesis(array2[i])== true || array2[i] == '+' || array2[i] =='-')
            {
                pushOper2('-');
                flag_minus2 =1;
                break;
            }
            
            else
            {
                push2(array2[i]);
                popOper2();
            }

        }
        if (flag_minus2 == 0)
        pushOper2('-');
    }
}
void Stack :: handleMultiply2 ()
{
    if (isClosingParanthesis(array2[top2-1]) == true)
    {
        pushOper2('*');
    }
    else
    {
        for (int i = top2-1; i>=0; i--)
        {
            if (isClosingParanthesis(array2[i])== true || array2[i]=='+' || array2[i]=='-' || array2[i]=='*' || array2[i]=='/')
            {
                pushOper2('*');
                flag_multiply2 = 1;
                break;
            }
            
            else
            {
                push2(array2[i]);
                popOper2();
            }
        }
        if (flag_multiply2 == 0)
        pushOper2('*'); 
    }
}
void Stack :: handleDivide2 ()
{
    if (isClosingParanthesis(array2[top2-1]) == true)
    {
        pushOper2('/');
    }
    else
    {
        for (int i = top2-1; i>=0; i--)
        {
            if (isClosingParanthesis(array2[i])== true || array2[i]=='+' || array2[i]== '-' || array2[i]=='*' || array2[i]=='/')
            {
                pushOper2('/');
                flag_divide2 = 1;
                break;
            }
            
            else
            {
                push2(array2[i]);
                popOper2();
            }
            
        }
        if (flag_divide2 == 0)
        {
            pushOper2('/');

        }
        
    }
}
void Stack :: handleExponent2 ()
{

    pushOper2('^');
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

bool Stack :: checkNull2 ()
{
    if (top2 == 0)
    return true;
    else 
    return false;
}
void Stack :: push (char ch)
{
    stt+=ch;
    cout <<"string  = "<<stt<<endl;
}
void Stack :: pushOper(char operand)
{
    // cout <<"operator "<<operand<<" has been pushed at position "<<top<<endl;
    array[top++] = operand;
}

void Stack :: push2 (char ch)
{
    stt2+=ch;
    cout <<"string  = "<<stt2<<endl;
}
void Stack :: pushOper2(char operand)
{
    cout <<"operator "<<operand<<" has been pushed at position "<<top2<<endl;
    array2[top2++] = operand;
}

string Stack :: reverseString (string strr)
{
    int leng = strr.size();
    string temp="";
    for (int i=leng-1; i>=0; i-- )
    {
        temp+=strr[i];
    }
    return temp;
}

int main ()
{
    Stack stack;
    string strng, strng2;
    cout <<"Enter the expression"<<endl;
    cin>>strng;
    strng2 = stack.reverseString (strng);
    int length = strng.size();
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
        stack.emptyStack();
    }
    // stack.displayString();



    for (int i =0; i<length; i++)
    {
        if ((strng2[i]>='a' && strng2[i]<='z') || (strng2[i]>='A' && strng2[i]<='Z'))
        {
            stack.push2(strng2[i]);
            
        }
        else if (stack.isOperand(strng2[i])== true && stack.checkNull() == true)
        {
            stack.pushOper2(strng2[i]);
        }
        else if (stack.isClosingParanthesis(strng2[i]) == true)
        {
            stack.pushOper2(strng2[i]);
        }
        else if (stack.isOperand(strng2[i])== true)
        {
            if (strng2[i] == '+')
            {
                stack.handlePlus2();
            }
            else if (strng2[i] == '-')
            {
                stack.handleMinus2();
            }
            else if (strng2[i] == '*')
            {
                stack.handleMultiply2();
            }
            else if (strng2[i] == '/')
            {
                stack.handleDivide2();
            }
            else if (strng2[i] == '^')
            {
                stack.handleExponent2();
            }
        }

        else if (stack.isParanthesis(strng2[i])== true)
        {
            if (strng2[i]=='(')
            {
                stack.handleClosingParan1ii();
            }
            else if (strng2[i] == '{')
            {
                stack.handleClosingParan2ii();
            }
            else if (strng2[i] == '[')
            {
                stack.handleClosingParan3ii();
            }
        }

    }
    // 2 = reverseString(strng2);
    if (stack.isStackEmpty2() == false)
    {
        stack.emptyStack2();
    }
    stack.displayString();

    return 0;


}