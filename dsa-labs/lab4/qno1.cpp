// SINGLY LINKED LIST
// LINKED LIST:
// WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN SINGLY LINEAR LINKED LIST:
// 1.     INSERTION OPERATIONS
// a.     INSERT NODE AT BEGINNING OF THE LIST
// b.     INSERT NODE AT END OF THE LIST
// c.      INSERT NODE AFTER SPECIFIC NODE
// d.     INSERT NODE BEFORE SPECIFIC NODE
// 2.     DELETION OPERATIONS
// a.     DELETE NODE FROM BEGINNING OF THE LIST
// b.     DELETE NODE FROM END OF THE LIST
// c.      DELETE NODE AFTER SPECIFIC NODE
// MAKE NECESSARY MODIFICATIONS IN ABOVE PROGRAM TO PERFORM OPERATIONS IN CIRCULAR LINKED LIST.


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
    struct Node* head;
    public:
    List()
    {
        head = NULL;
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
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;

}
void List :: deleteAtBeginning ()
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void List :: insertAtEnd (int value)
{
    if (head == NULL)
    {
        Node* node = new Node;
        node->data = value;
        node->next = NULL;
        head = node;
        return;
    }
    Node* i = head;
    while (i->next != NULL)
    {
        i = i->next;
    }
    Node* end = new Node;
    end->data = value;
    end->next = NULL;
    i->next = end;
    
}

void List :: deleteAtEnd ()
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node* i = head;
    Node* previous;
    while (i->next != NULL)
    {
        previous = i;
        i = i->next;
    }
    previous->next = NULL;
    delete i;   
}
void List :: insertAfter (int value, int after)
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }
    Node* i = head;
    while(i->data!= after)
    {
        i = i->next;
        if (i == NULL)
        break;
    }
    if (i == NULL)
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
    
    Node* i = head;
    while (i->data != after)
    {
        i = i->next;
        if (i == NULL)
        {
            cout <<after <<" is not an element of the list."<<endl;
            break;
        }
    }
    if (i == NULL)
    return;
    Node* temp = i->next;  //temp is to be deleted
    if (temp == NULL)
    {
        cout <<"No element exists after "<<after<<"."<<endl;
        return;
    }
    i->next = temp->next;

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
        insertAtBeginning(value);
        return;
    }
    Node* i = head;
    Node* previous;
    while (i->data!= before)
    {
        previous = i;
        i = i->next;
        if (i == NULL)
        {
            cout <<before <<" is not the element of the list."<<endl;
            break;
        }

    }
    if (i == NULL)
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
    while(i->next!= NULL)
    {
        cout <<i->data<<"   ";
        i = i->next;
    }
    cout <<i->data<<endl;
}
int main ()
{
    List list;
    int choice, before, num, after;
    bool quit = 0;
    while (quit == 0)
    {
        cout <<endl;
        cout <<"Press 1 to insert at beginning."<<endl;
        cout <<"Press 2 to insert before a specific value."<<endl;
        cout <<"Press 3 to insert after a specific value."<<endl;
        cout <<"Press 4 to insert at end."<<endl;
        cout <<"Press 5 to delete at beginning."<<endl;
        cout <<"Press 6 to delete after a specific value."<<endl;
        cout <<"Press 7 to delete at end."<<endl;
        cout <<"Press any other key to quit"<<endl<<endl;
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