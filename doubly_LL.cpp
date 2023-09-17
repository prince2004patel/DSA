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

int main(){
    // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    print(head);


    insertAtHead(tail,head,11);
    print(head);

    insertAtHead(tail,head,13);
    print(head);

    insertAtHead(tail,head,8);
    print(head);

    insertAtTail(tail,head,9);
    print(head);

    insertAtPosition(tail,head,2,100);
    print(head);

    insertAtPosition(tail,head,1,101);
    print(head);

    insertAtPosition(tail,head,7,103);
    print(head);

    deleteNode(1,tail,head);
    print(head);
   
    cout<<"length of doubly linked list: "<<getLength(head) << endl;
    // insertAtPosition(tail,head,7,103);
    // print(head);    

    cout << "head "<< head -> data <<endl;
    cout << "tail "<< tail -> data <<endl;
        


    return 0;

}