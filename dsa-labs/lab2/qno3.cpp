/*
3.	Perform operations in Deque( Double ended queue) for:
a.	Add at beginning
b.	Add at end
c.	Delete from beginning
d.	Delete from end
*/
#include <iostream>
using namespace std;
#define SIZE 5
class Dequeue
{
    int front, rear, array[SIZE];
    public:
    Dequeue ()
    {
        front =-1;
        rear =-1;
    }
    void insertFromFront(int);
    void insertFromRear(int);
    void deleteFromFront();
    void deleteFromRear();
    bool isEmpty();
    bool isFull();
    int getFront();
    int getRear();
    

};

bool Dequeue :: isEmpty()
{
    if (front == -1)
    return true;
    else 
    return false;
}

bool Dequeue :: isFull ()
{
    // cout <<"front = "<<front<<" rear = "<<rear<<endl;
    if ((front ==0 && rear == SIZE -1) || (front == rear +1))
    return true;
    else
    return false;

}
void Dequeue :: insertFromFront(int num)
{
    if (isFull())
    cout <<"Queue overflown"<<endl;
    else
    {
        if (front == -1)  // suru taal insert garda
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0) 
        front = SIZE -1;
        else
        front-=1;
        array[front] = num;
    }
}
void Dequeue :: insertFromRear(int num)
{
    if (isFull())
    cout <<"Queue overflown"<<endl;
    else
    {
        if (front ==-1)
        {
            front =0;
            rear =0;
        }
        else if (rear == SIZE-1)
        rear = 0;
        else
        rear+=1;
        array[rear] = num;
    }
}
void Dequeue :: deleteFromFront()
{
    if (isEmpty())
    cout <<"Queue underflown"<<endl;
    else
    {
        if (front == rear)
        {
            front =-1;
            rear =-1;
        }
        else if (front == SIZE-1)
        front =0;
        else
        {
            front +=1;
        }
    }
}
void Dequeue :: deleteFromRear()
{
    if (isEmpty())
    cout <<"Queue underflown"<<endl;
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        rear =SIZE-1;
        else
        rear--;
    }
}
int  Dequeue:: getFront()
{
    if (isEmpty())
    return -1;
    else
    {
        return (array[front]);
    }
}
int  Dequeue:: getRear()
{
    if (isEmpty())
    return -1;
    else
    return (array[rear]);
}
int  main()
{
    Dequeue dq;

    cout << "insert element at rear end \n";
    dq.insertFromRear(5);
    dq.insertFromRear(11);

    cout << "rear element: "<< dq.getRear() << endl;

    dq.deleteFromRear();
    cout << "after deletion of the rear element, the new rear element: " << dq.getRear() << endl;

    cout << "insert element at front end \n";

    dq.insertFromFront(8);

    cout << "front element: " << dq.getFront() << endl;

    dq.deleteFromFront();

    cout << "after deletion of front element new front element: " << dq.getFront() << endl;


    return 0;
}