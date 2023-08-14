#include <iostream>
using namespace std;


class Node{
    public:
    // data in linkedlist
    int data;

    // address of next data in linkedlist
    Node* next;

    // constructor
    Node(int data) {
        // defining data and next
        this -> data = data;
        this-> next = NULL;
    }


    // destructor
    ~Node() {
        int value = this-> data;
        // memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free" << endl;
    }
};




// Insertion at head/start
void InsertionAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);
    // point to head
    temp -> next = head;
    head = temp;
}




// Insertion at any position
void insertionAtPosition(Node* &head,Node* &tail, int position, int d) {

    // insert at starting
    if (position == 1)
    {
        InsertionAtHead(head,d);
        return;
    }
    
    Node* temp = head;
    int count = 1;

    while (count < position-1)
    {
        temp=temp->next;
        count++;
    }
    
    // creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    // insert at last
    if (temp->next == NULL)
    {
        InsertionAtTail(tail,d);
        return;
    }
}




// Insertion at tail/end
void InsertionAtTail(Node* &tail, int d) {
    // new node create
    Node* temp = new Node(d);
    // point to tail
    tail -> next = temp;
    tail = tail->next;
}




// Traversing a linkedlist
void print(Node* &head) {
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}




// deletion of a node
void deleteNode(int position, Node* &head) {
    
    // deleting first node
    if (position == 1)
    {   
        Node* temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    
}




int main()
{   
    // creating linked list
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;



    Node* head = node1;
    Node* tail = node1;
    print(head);
    print(tail);

    InsertionAtHead(head, 12);
    InsertionAtTail(tail, 15);
    insertionAtPosition(head, tail, 3, 18);

    print(head);
    print(tail);

    deleteNode(1, head);
    print(head);

    return 0;
}