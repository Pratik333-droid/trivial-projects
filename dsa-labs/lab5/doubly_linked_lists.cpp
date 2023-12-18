// doubly linked lists (linear)

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next, *previous;
    friend class List;
};

class List
{

    Node *head, *last;

public:
    List()
    {
        head = NULL;
        last = NULL;
    }
    void insertAtBeginning(int);
    void deleteAtBeginning();
    void insertAtEnd(int);
    void deleteAtEnd();
    void insertAfter(int, int);
    void deleteAfter(int);
    void insertBefore(int, int);
    void deleteBefore(int);
    void displayData();
};
void List ::insertAtBeginning(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->previous = NULL;
    temp->next = head;
    if (head == NULL) //if 
    {
        head = last = temp;
        return;
    }
    head->previous = temp;
    head = temp;
}
void List ::deleteAtBeginning()
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    if (head == last) // if there is only one element in the list
    {
        delete head;
        head = last = NULL;
        return;
    }
    Node *to_be_removed = head;
    head = head->next;
    head->previous = NULL;
    delete to_be_removed;
}
void List ::insertAtEnd(int value)
{
    if (head == NULL)
    {
        // If the list is empty then inserting an element in the end is same as inserting at the beginning.
        insertAtBeginning(value);
        return;
    }
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->previous = last;
    last->next = temp;
    last = temp;
}
void List ::deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }
    if (head == last)
    {
        // If the list contains only one element then deleting at end is same as deleting at beginning
        deleteAtBeginning();
        return;
    }
    Node *second_last = last->previous;
    second_last->next = NULL;
    delete last;
    last = second_last;
}
void List ::insertAfter(int value, int after)
{
    if (head == NULL)
    {
        cout << after << " doesn't exist in The list since the list is empty." << endl;
        return;
    }
    if (after == last->data)
    {
        insertAtEnd(value);
        return;
    }
    Node *iter = head;
    while (iter->data != after)
    {
        iter = iter->next;
        if (iter == NULL)
        {
            cout << after << " is not an element of the list." << endl;
            return;
        }
    }
    // value is to be inserted after iter.
    Node *node = new Node;
    node->data = value;
    node->next = iter->next;
    node->previous = iter;
    iter->next = node;
    (node->next)->previous = node;
}
void List ::deleteAfter(int after)
{
    if (head == NULL)
    {
        cout << "Invlid operation: The list is empty." << endl;
        return;
    }
    if (head == last)
    {
        cout << "Invalid operation. The list contains only one element." << endl;
        return;
    }
    if (after == (last->previous)->data) // deleting an element after the second last element is same as deleting at the end
    {
        deleteAtEnd();
        return;
    }
    if (after == last->data)
    {
        cout <<"There is no element after "<<after<<endl;
        return;
    }
    Node *iter = head;
    while (iter->data != after)
    {
        iter = iter->next;
        if (iter == NULL)
        {
            cout << after << " is not an element of the list." << endl;
            return;
        }
    }
    // node after iter is to be deleted
    Node *to_be_deleted = iter->next;
    iter->next = to_be_deleted->next;
    (to_be_deleted->next)->previous = iter;
}
void List ::insertBefore(int value, int before)
{
    if (head == NULL)
    {
        cout <<"The list is empty."<<endl;
        return;
    }
    if (before == head->data) // if an element is to be inserted before head
    {
        // inserting an element before head is same as inserting an element at the very beginning
        insertAtBeginning(value);
        return;
    }
    Node *iter = head;
    while (iter->data != before)
    {
        iter = iter->next;
        if (iter == NULL)
        {
            cout << before << " is not an element of the list." << endl;
            return;
        }
    }
    // node is to be inserted before iter.
    int after = (iter->previous)->data;
    // now that node is to be inserted after the variable after
    insertAfter(value, after);
    return;
}
void List ::deleteBefore(int before)
{
    if (head == NULL)
    {
        cout << "Invalid operation 'delete before'. The list is empty." << endl;
        return;
    }
    if (before == head->data)
    {
        cout <<"There is no element before "<<before<<endl;
        return;
    }
    if (before == (head->next)->data) // if a node before the second node is to be deleted, the operation is same as deleting at beginning
    {
        deleteAtBeginning();
        return;
    }

    Node *iter = head;
    while (iter->data != before)
    {
        iter = iter->next;
        if (iter == NULL)
        {
            cout << "Invalid operation 'delete before'. " << before << " is not an element of the list." << endl;
            return;
        }
    }
    // node before iter is to be deleted
    Node *after = (iter->previous)->previous;
    // now that the node after 'after' is to be deleted. This is same as deleting after 'after->data'
    deleteAfter(after->data);
}
void List ::displayData()
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "The elements of the lists are displayed below." << endl;
    Node *iter = head;
    while (iter->next != NULL)
    {
        cout << iter->data << "   ";
        iter = iter->next;
    }
    cout << iter->data << endl;
}

int main()
{
    List list;
    int choice, num, before, after;
    bool quit = 0;
    while (quit == 0)
    {
        /* code */
        cout << "Press 1 to insert at beginning." << endl;
        cout << "Press 2 to insert before a specific value." << endl;
        cout << "Press 3 to insert after a specific value." << endl;
        cout << "Press 4 to insert at end." << endl;
        cout << "Press 5 to delete at beginning." << endl;
        cout << "Press 6 to delete before a specific value." << endl;
        cout << "Press 7 to delete after a specific value." << endl;
        cout << "Press 8 to delete at end." << endl;
        cout << "Press 9 to display the elements." << endl;
        cout << "Press any other key to quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number to insert at beginning." << endl;
            cin >> num;
            list.insertAtBeginning(num);
            list.displayData();
            break;
        case 2:
            cout << "Enter the number you would like to insert." << endl;
            cin >> num;
            cout << "Enter the number before which you would like to insert the entered number." << endl;
            cin >> before;
            list.insertBefore(num, before);
            list.displayData();
            break;
        case 3:
            cout << "Enter the number you would like to insert." << endl;
            cin >> num;
            cout << "Enter the number after which you would like to insert the entered number." << endl;
            cin >> after;
            list.insertAfter(num, after);
            list.displayData();
            break;
        case 4:
            cout << "Enter the number to insert at end." << endl;
            cin >> num;
            list.insertAtEnd(num);
            list.displayData();
            break;
        case 5:
            list.deleteAtBeginning();
            list.displayData();
            break;

        case 6:
            cout << "Enter the value before which you would like to delete." << endl;
            cin >> before;
            list.deleteBefore(before);
            list.displayData();
            break;
        case 7:
            cout << "Enter the value after which you would like to delete." << endl;
            cin >> after;
            list.deleteAfter(after);
            list.displayData();
            break;
        case 8:
            list.deleteAtEnd();
            list.displayData();
            break;
        case 9:
            list.displayData();
            break;
        default:
            cout << "Terminating the program." << endl;
            quit = 1;
            break;
        }
    }
    return 0;
}