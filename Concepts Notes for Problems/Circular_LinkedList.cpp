#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is Freed" << endl;
    }
};




void insertNode(Node *&tail, int element, int d)
{
    // assume the elemnt is present in the list

    // if list is empty
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        // non empty list
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}




// traversing
void print(Node *tail)
{
    Node *temp = tail;

    if(tail == NULL) {
        cout << "List is Empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}




// deletion
void deleteNode(Node *&tail, int val)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        // non empty
        // val is present
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // single node
        if(curr == tail) {
            tail == NULL;
        }

        // two or more node
        else if(tail == curr) {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}





int main()
{
    Node *tail = NULL;

    // insert in empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 8);
    print(tail);

    insertNode(tail, 8, 11);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    insertNode(tail, 11, 13);
    print(tail);

    deleteNode(tail, 8);
    print(tail);


    return 0;
}