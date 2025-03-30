/*

Company Tags:

        VMWare
        Amazon
        Microsoft
        Oracle


*/


//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends

/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeNode(Node* head1, Node* head2) {
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        
        while(head1!=NULL && head2!=NULL) {
            if(head1->data <= head2->data) {
                curr->next=head1;
                head1=head1->next;
            } else {
                curr->next=head2;
                head2=head2->next;
            }
            
            curr=curr->next;
        }
        
        if(head1!=NULL) curr->next=head1;
        else curr->next=head2;
        
        return dummy->next;
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* res = NULL;
        
        for(Node* node : arr) {
            res = mergeNode(res, node);
        }
        
        return res;
    }
};



//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends