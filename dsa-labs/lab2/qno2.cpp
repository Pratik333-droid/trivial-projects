// 2.	Perform enqueue and dequeue operations in Circular Queue
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
    if ((rear == sizeq-1 && front == 0) || (front == rear + 1))
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
        rear = (rear+1)%sizeq;
        array[rear] = value;

    }
}

void Queue :: dequeue()
{
    if (isEmpty())
    cout <<"Can't dequeue. The queue is empty"<<endl;
    
    else 
    {

        cout <<array[front]<<" has been dequeued."<<endl;
        if (front == rear)
        front = rear = -1;
        else
        {
            front = (front+1)%sizeq;
        }
    }
}

void Queue :: display()
{
    cout <<"The elements of queue are "<<endl;
    if (isEmpty())
    {
        cout <<"The queue is empty"<<endl;
    }
    else
    {
        int count =0;
        cout<<"front = "<<front<<" and rear == "<<rear<<endl;
        for (int i =front; i!= rear; i=(i+1)%sizeq)
        {
            // cout <<"frnt ="<<front<<" rer = "<<rear<<endl;
            cout <<array[i]<<" ";
        }
        cout<<array[rear];
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
    q.dequeue();
    q.enqueue(6);
    q.enqueue(7);
    q.display();
    q.dequeue();
    q.enqueue(8);

    //Now we have just 4 elements
    q.display();

    return 0;
}