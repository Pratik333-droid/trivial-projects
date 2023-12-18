#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
    int avail;
    struct Node *head, *last;
    public:
    List()
    {
        head = NULL;
        last = NULL;
    }
    void insertAtBeginning (int);
    void deleteAtBeginning ();
    void insertAtEnd (int);
    void deleteAtEnd ();
    void insertAfter (int, int);
    void deleteAfter (int);
    void insertBefore (int, int);
    void displayData ();

};

void List :: insertAtBeginning (int value)
{
    if (head == NULL)
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = temp;
        head = temp; 
        last = temp;
        return;
    }
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
    last->next = head;


}
void List :: deleteAtBeginning ()
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }
    //if there is only one element
    if (head == last)
    {
        delete head;
        head = last = NULL;
        return;
    }
    Node* temp = head;
    head = head->next;
    last->next = head;
    delete temp;
}
void List :: insertAtEnd (int value)
{
    if (head == NULL)
    {
        // cout <<"I am here mofo"<<endl;
        Node* node = new Node;
        // cout <<"I am here mofo"<<endl;
        node->data = value;
        // cout <<"I am here mofo"<<endl;
        node->next = node;
        // cout <<"I am here mofo"<<endl;
        head = node;
        last = node;
        // cout <<"I am here mofo"<<endl;
        return;
    }
    // Node* i = head;
    // int count = 0;
    // while (i->next != NULL)
    // {
    //     count++;
    //     i = i->next;
    //     if (count>10)
    //     {
    //         cout <<"Infinite loop detected."<<endl;
    //         break;
    //     }
    // }
    Node* end = new Node;
    end->data = value;
    end->next = head;
    last->next = end;
    last = end;
    
}


void List :: deleteAtEnd ()
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }
    Node* i = head;
    if (last == head)
    {
        delete head;
        head = last = NULL;
        return;
    }
    Node* previous;
    while (i->next != head)
    {
        previous = i;
        i = i->next;
    }
    previous->next = head;
    last = previous;
    delete i;   
}
void List :: insertAfter (int value, int after)
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }
    if (after == last->data)
    {
        Node *end = new Node;
        end->data = value;
        end->next = head;
        last->next = end;
        last = end;
        return;
    }
    Node* i = head;
    while(i->data!= after)
    {
        i = i->next;
        if (i == head)
        break;
    }
    if (i == head)
    {
        cout <<after <<" is not an element of the list."<<endl;
        return;
    }
    Node* temp = new Node;
    temp->data = value;
    temp->next = i->next;
    i->next = temp;
}
void List :: deleteAfter (int after)
{
    if (head == NULL)
    {
        cout <<" Invalid oPeration. The list is empty."<<endl;
        return;
    }
    if (head->next == head)
    {
        cout <<"There is no element after "<<after<<"."<<endl;
        return;
    }
    if (after == head->data)
    {
        Node *temp = head->next;  //temp is to be removed
        head->next = temp->next;
        delete temp;
        return;
    }
    Node* i = head;
    while (i->data != after)
    {
        i = i->next;
        if (i == head)
        {
            cout <<after <<" is not an element of the list."<<endl;
            break;
        }
    }
    if (i == head)
    return;
    Node* temp = i->next;  //temp is to be deleted
    i->next = temp->next;
    if (temp == head) 
    head = head->next;
    if (temp == last)
    last = i;
    delete temp;
}
void List :: insertBefore (int value, int before)
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }
    if (before == head->data)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
        last->next = head;
        return;
    }
    Node* i = head;
    Node* previous;
    while (i->data!= before)
    {
        previous = i;
        i = i->next;
        if (i == head)
        {
            cout <<before <<" is not the element of the list."<<endl;

            break;
        }

    }
    if (i == head)
    return;
    Node* temp = new Node;
    temp->data = value;
    previous->next = temp;
    temp->next = i;
}
void List :: displayData ()
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }

    cout <<"The elements of the list are displayed below."<<endl;
    Node* i = head;
    while(i->next!= head)
    {
        cout <<i->data<<"   ";
        i = i->next;
    }
    cout <<i->data<<endl;
}
int main ()
{
    List list;
    int choice, num, before, after;
    bool quit = 0;
    while (quit == 0)
    {
        /* code */
        cout <<"Press 1 to insert at beginning."<<endl;
        cout <<"Press 2 to insert before a specific value."<<endl;
        cout <<"Press 3 to insert after a specific value."<<endl;
        cout <<"Press 4 to insert at end."<<endl;
        cout <<"Press 5 to delete at beginning."<<endl;
        cout <<"Press 6 to delete after a specific value."<<endl;
        cout <<"Press 7 to delete at end."<<endl;
        cout <<"Press any other key to quit"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout <<"Enter the number to insert at beginning."<<endl;
            cin>>num;
            list.insertAtBeginning(num);
            break;
        case 2:
            cout <<"Enter the number you would like to insert."<<endl;
            cin>>num;
            cout <<"Enter the number before which you would like to insert the entered number."<<endl;
            cin>>before;
            list.insertBefore(num, before);
            break;
        case 3:
            cout <<"Enter the number you would like to insert."<<endl;
            cin>>num;
            cout <<"Enter the number after which you would like to insert the entered number."<<endl;
            cin>>after;
            list.insertAfter(num, after);
            break;
        case 4:
            cout <<"Enter the number to insert at end."<<endl;
            cin>>num;
            list.insertAtEnd(num);
            break;
        case 5:
            list.deleteAtBeginning();
            break;
        case 6:
            cout <<"Enter the value after which you would like to delete."<<endl;
            cin>>after;
            list.deleteAfter(after);
            break;
        case 7:
            list.deleteAtEnd();
            break;
        default:
            cout <<"Terminating the program."<<endl;
            quit = 1;
            break;
        }

        list.displayData();
    }
    

    return 0;
}