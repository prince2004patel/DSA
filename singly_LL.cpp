// singly linked list

#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *HEAD = NULL;
void insertfirst(int val)
{
    struct node *x;
    x = new struct node;
    x->data = val;
    x->next = NULL;
    x->next = HEAD;
    HEAD = x;
}
void insertlast(int val)
{
    struct node *p, *x;
    x = new struct node;
    x->data = val;
    x->next = NULL;
    if (HEAD == NULL)
    {
        HEAD = x;
    }
    else
    {
        p = HEAD;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = x;
    }
}
void deletefirst()
{
    struct node *temp;
    if (HEAD == NULL)
    {
        cout << "List is Empty " << endl;
    }
    if (HEAD->next == NULL)
    {
        temp = HEAD;
        HEAD = NULL;
        delete temp;
    }
    else
    {
        temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
    }
}
void deletelast()
{
    if (HEAD == NULL)
        cout << "List is Empty \n";
    else
    {
        struct node *p, *temp;
        p = HEAD;
        if (p->next == NULL)
        {
            temp = p;
            HEAD = NULL;
            delete temp;
            return;
        }
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        delete temp;
    }
}
void display()
{
    struct node *p;
    p = HEAD;
    if (HEAD == NULL)
    {
        cout << " List Is Empty " << endl;
    }
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int number;
    int a, b;
    cout << "Enter 1 to Insert at FRONT" << endl;
    cout << "Enter 2 to Insert at REAR" << endl;
    cout << "Enter 3 to Delete from FRONT" << endl;
    cout << "Enter 4 to Delete from REAR" << endl;
    cout << "Enter 5 to DISPLAY the list" << endl;
    cout << "Enter 6 to EXIT" << endl;
    do
    {
        cout << "Enter your choice : ";
        cin >> number;
        cout << endl;
        switch (number)
        {
        case 1:
            cout << "Insert at FRONT" << endl;
            cout << "Enter the value to Insert : ";
            cin >> a;
            cout << endl;
            insertfirst(a);
            break;
        case 2:
            cout << "Insert at REAR" << endl;
            cout << "Enter the value to Insert : ";
            cin >> a;
            cout << endl;
            insertlast(a);
            break;
        case 3:
            deletefirst();
            break;
        case 4:
            deletelast();
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "EXIT" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
        // display();
    } while (number != 6);
}
