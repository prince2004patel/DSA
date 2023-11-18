// doubly linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

// traversing a linked list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&tail, Node *&head, int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{

    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at start
    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last  position
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // inserting at in Between
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteFirst(Node *&tail, Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty. Cannot delete.\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }
    else
    {
        // If the list becomes empty after deletion
        tail = NULL;
    }

    temp->next = NULL;
    delete temp;
}

void deleteLast(Node *&tail, Node *&head)
{
    if (tail == NULL)
    {
        cout << "List is empty. Cannot delete.\n";
        return;
    }

    Node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
    {
        tail->next = NULL;
    }
    else
    {
        // If the list becomes empty after deletion
        head = NULL;
    }

    temp->prev = NULL;
    delete temp;
}

void deleteNode(int position, Node *&tail, Node *&head)
{
    if (position == 1)
    {
        deleteFirst(tail, head);
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL)
        {
            cout << "Invalid position. Cannot delete.\n";
            return;
        }

        if (curr->next == NULL)
        {
            // Deleting the last node
            deleteLast(tail, head);
        }
        else
        {
            // Deleting a node in between
            curr->prev = NULL;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

// gives length of linked list
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// ... (your Node class and functions)

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int choice;
    int data;
    int position;

    // Print menu outside the loop
    cout << "Menu:\n";
    cout << "1. Insert at Head\n";
    cout << "2. Insert at Tail\n";
    cout << "3. Insert at Position\n";
    cout << "4. Delete Node at Position\n";
    cout << "5. Delete First Node\n";
    cout << "6. Delete Last Node\n";
    cout << "7. Print List\n";
    cout << "8. Get Length\n";
    cout << "9. Exit\n";

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at head: ";
            cin >> data;
            insertAtHead(tail, head, data);
            break;
        case 2:
            cout << "Enter data to insert at tail: ";
            cin >> data;
            insertAtTail(tail, head, data);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter data to insert at position " << position << ": ";
            cin >> data;
            insertAtPosition(tail, head, position, data);
            break;
        case 4:
            cout << "Enter position to delete: ";
            cin >> position;
            deleteNode(position, tail, head);
            break;
        case 5:
            deleteFirst(tail, head);
            break;
        case 6:
            deleteLast(tail, head);
            break;
        case 7:
            cout << "Doubly Linked List: ";
            print(head);
            break;
        case 8:
            cout << "Length of doubly linked list: " << getLength(head) << endl;
            break;
        case 9:
            // Exit the program
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
