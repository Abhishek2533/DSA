/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *reverseLinkedList(Node *head)
{

    // empty or one node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = NULL;
    Node *prev = NULL;

    while (head != NULL)
    {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return prev;
}
