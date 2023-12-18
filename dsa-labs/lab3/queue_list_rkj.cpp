//queue as list
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define numnodes 5
using namespace std;

struct node{
    int info,next;
};
struct Queue{
    private:
    int front =-1, rear=-1, avail=-1;
    struct node n[numnodes];
    int getnode(void){
        int p;
        if (avail==-1){
            cout<<"Overflow."<<endl;
            return -1;
        }
        p=avail;
        avail=n[avail].next;
        return p;
    }
    void freenode(int p){
        n[p].next=avail;
        avail=p;
        return;
    }
    void init(){
        avail=0;
        for(int i=0;i<numnodes-1;i++){
            n[i].next=i+1;
        }
        n[numnodes-1].next=-1;
    }
    public:
    bool empty(){
        return ((front==-1)? true:false);
    }
    Queue(){
        init();
    }
    void insert (int x){
        int p;
        
        p=getnode();
        if (p == -1)
        return;
        n[p].info=x;
        n[p].next=-1;
        cout <<x<<" has been inserted."<<endl;
        if (rear==-1) // suru choti data halda ko case ma
        {

            front=p;
            cout <<"rear == -1 as expected."<<endl;
        }
        
        else
        n[rear].next=p;
        rear=p;
    }
    int remove(){
        int p,x;
        if(empty()){
            cout<<"Underflow."<<endl;
            return -1;
        }
        p=front;
        x=n[p].next;
        front=n[p].next;
        if (front==-1)
        rear=-1;
        freenode(p);
        return p;
    }

    void display ()
    {
        cout <<"the elements of the array are"<<endl;
        for (int i = front; i<=rear; i++)
        {
            cout <<n[i].info<<"  ";
        }
    }
};

int main(){
    struct Queue q;
    for (int i=0;i<7;i++){
        q.insert(i);
    }
    for (int i=0;i<4;i++){
        cout<<q.remove()<<"  ";
    }
    cout <<endl;
    q.display();
    return 0;
}