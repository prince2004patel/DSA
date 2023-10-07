#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
   
    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val <<endl;
    }

};

//traversing a linked list
void print(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<< endl;
}


void insertAtHead(Node* &tail,Node* &head, int d){

    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}

void insertAtTail(Node* &tail,Node* &head, int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){

    //insert at start
    if(position == 1){
        insertAtHead(tail,head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    //inserting at last  position
    if(temp -> next == NULL){
        insertAtTail(tail,head,d);
        return;
    }

    //inserting at in Between
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position,Node* &tail,Node* &head){

    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        
        if(curr-> next == NULL){
            curr -> prev = NULL;
            prev -> next = NULL;
            tail = prev;
            delete curr;

        }
        else{
            curr -> prev = NULL;
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
    }

}
//gives length of linked list
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;

}


// ... (your Node class and functions)

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int choice;
    int data;
    int position;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Node\n";
        cout << "5. Print List\n";
        cout << "6. Get Length\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
                cout << "Doubly Linked List: ";
                print(head);
                break;
            case 6:
                cout << "Length of doubly linked list: " << getLength(head) << endl;
                break;
            case 7:
                // Exit the program
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
