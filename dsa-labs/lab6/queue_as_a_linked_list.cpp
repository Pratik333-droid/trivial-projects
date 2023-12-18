#include <iostream>
using namespace std;

class Node 
{
    int data;
    Node *next;
    friend class Queue;
};

class Queue
{
    Node *front, *rear;
    public:
    Queue ()
    {
        front = rear = NULL;
    }
    void enqueue(int);
    void dequeue();
    void display();
};

void Queue :: enqueue(int value)
{
    Node *node = new Node;
    node->data = value;
    node->next = NULL;
    if (front == NULL && rear == NULL)
    {

        front = rear = node;
    }
    else
    {
       rear->next = node;
       rear = node; 
    }
}
void Queue :: dequeue()
{
    if (front == NULL)
    cout <<"Can't dequeue."<<endl;
    else
    {
        Node *temp = front;
        if (front->next == NULL)
        {
            delete temp;
            front = rear = NULL;
            return;
        }
        front = front->next;
        delete temp;
    }
}
void Queue :: display()
{
    if (front == NULL)
    {
        cout <<"Queue is empty."<<endl;
        return;
    }
    cout <<"The elements of the queue are "<<endl;
    Node *iter = front;
    while (iter!= NULL)
    {
        cout <<iter->data<<"   ";
        iter = iter->next;
    }
    cout <<endl;
}
int main()
{
    int choice, num;
    bool quit = 0;
    Queue queue;
    while (quit == 0)
    {   
        cout <<"Press 1 to enqueue."<<endl;
        cout <<"Press 2 to dequeue."<<endl;
        // cout <<"Press 3 to pop."<<endl;
        cout <<"Press any key to quit."<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:

            /* code */
            cout <<"Enter the element to enqueue."<<endl;
            cin>>num;
            queue.enqueue(num);
            queue.display();
            break;
        case 2:
            queue.dequeue();
            queue.display();
            break;

        default:
            cout <<"Terminating the program."<<endl;
            quit = 1;
            break;
        }
    }

    return 0;
}