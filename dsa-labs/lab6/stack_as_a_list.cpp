#include <iostream>
using namespace std;
//push pop peek display

class Node
{
    int data;
    Node *link;
    friend class List;
};

class List
{
    Node *top;
    public:
    List()
    {
        top = NULL;
    }
    void push(int);
    void peek();
    void pop();
    void display();
};

void List:: push(int value)
{
    Node *node = new Node;
    node->data = value;
    node->link = top;
    top = node;
    cout <<"top = "<<top<<endl;
}
void List:: peek()
{
    if (top == NULL)
    cout <<"The stack is empty."<<endl;
    else
    cout <<"The element at the top is "<<top->data<<endl;
}
void List:: pop()
{
    if (top == NULL)
    cout <<"Invalid operation. The list is empty."<<endl;
    else
    {
        Node *temp = top;
        cout <<top->data<<" has been popped."<<endl; 
        top= top->link;
        delete temp;
    }
}
void List:: display()
{
    if (top == NULL)
    {
        cout <<"The stack is empty."<<endl;
        return;
    }
    cout <<"The elements of stack are :"<<endl;
    Node *iter = top;
    while (iter!= NULL)
    {
        cout <<iter->data<<"  ";
        iter= iter->link;
    }
    cout <<endl;
    
}
int main ()
{
    int choice, num;
    bool quit = 0;
    List list;
    while (quit == 0)
    {   
        cout <<"Press 1 to Push elements into the stack."<<endl;
        cout <<"Press 2 to Peek into the top of the stack."<<endl;
        cout <<"Press 3 to pop."<<endl;
        cout <<"Press any key to quit."<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:

            /* code */
            cout <<"Enter the element to push."<<endl;
            cin>>num;
            list.push(num);
            list.display();
            break;
        case 2:
            list.peek();
            break;
        case 3:
            list.pop();
            list.display();
            break;
        default:
            cout <<"Terminating the program."<<endl;
            quit = 1;
            break;
        }
    }
    return 0;
}
