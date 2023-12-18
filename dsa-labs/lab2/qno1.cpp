/*
Write an algorithm and program code for the following:
1.	Perform enqueue and dequeue operations in Linear Queue  

2.	Perform enqueue and dequeue operations in Circular Queue


3.	Perform operations in Deque( Double ended queue) for:
a.	Add at beginning
b.	Add at end
c.	Delete from beginning
d.	Delete from end
*/
const int sizeq = 5;
#include <iostream>
using namespace std;

class Queue
{
    int front, rear;
    int array[sizeq];
    public:
    Queue()
    {
        front =-1;
        rear = -1;
    }
    void enqueue(int);
    void dequeue();
    bool isEmpty();
    bool isFull ();
    void display();
};
bool Queue :: isFull()
{
    if (rear == sizeq-1 && front == 0)
    return true;
    else 
    return false;
}
bool Queue :: isEmpty()
{
    if (front == -1)
    return true;
    else 
    return false;
}
void Queue :: enqueue (int value)
{
    if (isFull())
    cout <<"Queue is full. Can't add items"<<endl;
    else
    {
        if (isEmpty())
        front =0;
        array[++rear] = value;

    }
}

void Queue :: dequeue()
{
    if (isEmpty())
    cout <<"Can't dequeue. The queue is empty"<<endl;
    
    else 
    {

        cout <<array[front++]<<" has been dequeued."<<endl;
        if (front > rear)
        front = rear = -1;
    }
}

void Queue :: display()
{
    cout <<"front = "<<front <<" rear = "<<rear<<endl;
    cout <<"The elements of queue are "<<endl;
    if (isEmpty())
    {
        cout <<"The queue is empty"<<endl;
    }
    else
    {
        for (int i =front; i<=rear; i++)
        cout <<array[i]<<" ";
        cout <<endl;
    }

}
int main ()
{
    Queue q;
     //deQueue is not possible on empty queue
    q.dequeue();

    //enQueue 5 elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // 6th element can't be added to because the queue is full
    q.enqueue(6);

    q.display();

    //deQueue removes element entered first i.e. 1
    for (int i=0; i<2; i++)
    {
        q.dequeue();
    }
    

    q.enqueue(7);
    q.enqueue(9);

    //Now we have just 4 elements
    q.display();

    return 0;
}