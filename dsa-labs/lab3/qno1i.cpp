#include <iostream>
#define MAXSIZE 15
using namespace std;

struct Node
{
    int data, next;
};

class List
{
    int avail, head;
    struct Node node[MAXSIZE];
    void insertAfterNode(int, int);
    void deleteAfterNode(int);

public:
    List(int value)
    {
        head = 0;
        avail = 1;
        initialize();
        node[head].data = value;
        node[head].next = -1;
    }
    void initialize();
    int getNode();
    void freeNode(int);
    void display();

    void insertAtBeginning(int);
    void insertAtEnd(int);
    void insertAfterValue(int, int);
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteAferValue(int);
};
void List ::freeNode(int freenode)
{
    node[freenode].next = avail;
    avail = freenode;
}
void List ::initialize()
{
    for (int i = 0; i < MAXSIZE - 1; i++)
        node[i].next = i + 1;
    node[MAXSIZE - 1].next = -1;
}
int List ::getNode()
{
    if (avail != -1)
        return avail;
    else
    {
        cout << "No available node" << endl;
        return -1;
    }
}
void List ::insertAtBeginning(int value)
{
    int next_node = getNode();
    if (next_node == -1)
        return;
    node[next_node].data = value;
    avail = node[next_node].next;
    node[next_node].next = head;
    head = next_node;
}
void List ::insertAtEnd(int value)
{
    int x = head;
    int count = 0;
    int next_node = getNode();
    if (next_node == -1)
        return;
    while (node[x].next != -1 && count < MAXSIZE)
    {
        x = node[x].next;
        count++;
    }
    if (node[x].next == -1)
    {
        node[next_node].data = value;
        node[x].next = next_node;
        avail = node[next_node].next;
        node[next_node].next = -1;
    }
    else
    {
        cout << "Something ain't no right." << endl;
    }
}

void List ::insertAfterNode(int pos, int data) // inserts data at a specified position
{
    int next_node = getNode();
    if (next_node == -1)
        return;
    node[next_node].data = data;
    int temp = node[pos].next;
    node[pos].next = next_node;
    avail = node[next_node].next;
    node[next_node].next = temp;
}
void List ::insertAfterValue(int value, int data) // inserts data after a specified node value
{
    int x = head;
    // cout <<"head = "<<head<<endl;
    while (node[x].data != value)
    {
        // cout <<" x = "<<x<<endl;
        x = node[x].next;
        if (x == -1)
        {
            cout << "invalid node." << endl;
            break;
        }
    }
    if (x != -1)
        insertAfterNode(x, data);
}

void List ::deleteAtBeginning()
{
    if (head != -1)
    {
        int temp = head;
        head = node[head].next;
        freeNode(temp);
    }
    else
    {
        cout << "Empty node" << endl;
    }
}
void List ::deleteAtEnd()
{
    if (head != -1)
    {
        int x = head;
        int count = 0;
        int previous = x;
        while (node[x].next != -1 && count < MAXSIZE)
        {
            count++;
            previous = x;
            x = node[x].next;
        }
        if (node[x].next == -1)
        {
            node[previous].next = -1;
            freeNode(x);
        }
        else
        {
            cout << "Something is not right" << endl;
        }
    }
}
void List ::deleteAferValue(int value)
{
    int x = head;
    while (node[x].data != value)
    {
        x = node[x].next;
        if (x == -1)
        {
            cout << x << " is not in the node. Invalid input." << endl;
            break;
        }
    }

    if (node[x].data == value)
    {

        deleteAfterNode(x);
    }
}
void List ::deleteAfterNode(int pos) // node after node[pos] will be deleted
{
    int temp;
    temp = node[pos].next; // temp is to be deleted
    node[pos].next = node[temp].next;
    freeNode(temp);
}

void List ::display()
{
    cout << "The elements are:" << endl;
    int i = head;
    if (i == -1)
        cout << "The node is empty." << endl;
    while (i != -1)
    {
        cout << "node [" << i << "] = " << node[i].data << " next = " << node[i].next << endl;
        i = node[i].next;
    }
}
int main()
{
    List list(333);
    list.insertAtBeginning(12);
    list.insertAtEnd(14);
    list.insertAfterValue(12, 13);
    // list.insertAfterValue(14, 6);
    // list.insertAtBeginning(55);
    // list.insertAfterValue(55, 56);
    // list.insertAtEnd(600);
    // list.insertAfterValue(600, 601);
    list.deleteAferValue(12);

    list.deleteAtBeginning();
    list.deleteAtEnd();
    // list.deleteAferValue(56);
    list.display();

    return 0;
}