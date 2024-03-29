/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *kReverse(Node *head, int k)
{
    int size = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    if (size < k)
        return head;

    // base case
    if (head == NULL)
    {
        return NULL;
    }

    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    // reverse first k nodes
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // recursion do next
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }

    return prev;
}