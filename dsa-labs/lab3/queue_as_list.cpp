#include <iostream>
using namespace std;
#define MAXSIZE 5

struct Node
{
    int data, next;
};

struct Queue 
{
    /* data */
    int front, rear, avail;
    struct Node node[MAXSIZE];
    void initialize ()
    {
        // cout <<"Initialization done and dusted."<<endl;
        front= rear = -1;
        avail = 0;
        for (int i=0; i<MAXSIZE-1; i++)
        {
            node[i].next = i+1;
        }
        node[MAXSIZE-1].next = -1;
    }
    bool checkEmpty ()
    {
        if (front == -1 || front == node[rear].next)
        return true;
        else 
        return false;

    }
    bool checkFull()
    {
        if (avail == -1)
        return true;
        else
        return false;
    }

    int getNode ()
    {
        int p = avail;
        if (p !=-1)
        {
            avail = node[avail].next;
            
        }
        else
        cout <<"Node is full."<<endl;
        return p;

    }

    void freeNode (int freenode)
    {
        node[freenode].next = avail;
        avail = freenode;
    }
    Queue()
    {
        initialize();
    }
    void insertData (int value)
    {
        // first in first out
        if (checkFull())
        {
            cout <<"Queue is full. Can't add items."<<endl;
            return;
        }
        int index = getNode();
        node[index].data = value;
        node[index].next = -1;
        if (front == -1) // suru choti data halda ko case ma
        {
            front = index;
            
        }
        else
        node[rear].next = index;
        rear = index;

    }

    void deleteData ()
    {
        if (checkEmpty())
        {
            cout <<"Queue is empty. Can't delete items."<<endl;
            return ;
        }
        int free = front;
        front = node[front].next;
        if (front ==-1)
        {
            cout <<"This condition is reached."<<endl;
            rear =-1;
        }
        
        freeNode(free);
    }
    void displayData ()
    {
        if (front == -1)
        {
            cout <<"The queue is empty"<<endl;
            return;
        }
        cout <<"The elements of the queue are"<<endl;
        // for (int i= front; i!=rear; i = node[i].next)
        // cout <<"Node ["<<i<<"] = "<<node[i].data<<"  "<<endl;
        // cout <<"Node ["<<rear<<"] = "<<node[rear].data<<endl;
        int i = front;
        while (node[i].next!= -1)
        {
            cout <<"Node ["<<i<<"] = "<<node[i].data<<"  "<<endl;
            i = node[i].next;
        }
        
        cout <<"Node ["<<i<<"] = "<<node[i].data<<"  "<<endl;

        
    }


};

int main()
{
    struct Queue q;
    for (int i =0; i<5; i++)
    q.insertData(5*i);
    q.displayData();
    q.deleteData();
    q.displayData();
    // q.deleteData();
    // q.displayData();
    // q.insertData(100);
    // q.displayData();
    // q.insertData(101);
    // q.displayData();
    // q.insertData(555);
    // q.displayData();
    // for (int i=0; i<4; i++)
    // q.deleteData();
    // q.displayData();
    // q.deleteData();
    // q.displayData();
    // q.deleteData();
    return 0;
}