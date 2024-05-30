#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[], int i = 0)
{
    // Write your code here.
    if (head == nullptr)
    {
        return head;
    }

    if (i >= n)
    {
        return head;
    }

    if (b[i] == 0)
    {
        return getListAfterReverseOperation(head, n, b, i + 1);
    }

    Node *prev = nullptr;
    Node *nextNode = nullptr;
    Node *curr = head;
    int k = 0;
    while (k < b[i] && curr != nullptr)
    {
        k++;
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    if (curr != nullptr)
    {
        head->next = getListAfterReverseOperation(curr, n, b, i + 1);
    }

    return prev;
}