#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node() {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed" << endl;
    }
};


// traversing
void print(Node* head) {
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


// finding the length of Linked list
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}



// insertion at head / start
void insertAtHead(Node* &head, Node* &tail, int d) {
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(d);
        temp-> next = head;
        head->prev = temp;
        head = temp;
    }
    
    
}




// insertion at tail / end
void insertAtTail(Node* &head, Node* &tail, int d) {
    if (tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(d);
        tail-> next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}




// insertion at any position
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
     // insert at starting
    if (position == 1)
    {
        insertAtHead(head, tail, d);
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
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;


    // insert at last
    if (temp->next == NULL)
    {
        insertAtTail(tail, tail, d);
        return;
    }
}




// deletion of a node
void deleteNode(int position, Node* &head) {
    
    // deleting first node
    if (position == 1)
    {   
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    
}





int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    // printing the length
    cout << getLength(head) << endl;


    insertAtHead(head, tail, 12);
    print(head);
    
    insertAtTail(head, tail, 15);
    print(tail);

    insertAtPosition(head, tail, 1, 18);
    print(head);

    return 0;
}