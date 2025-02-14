/*

Company Tags:

        Flipkart
        Morgan Stanley
        Accolite
        Amazon
        Microsoft
        Snapdeal
        MakeMyTrip
        Qualcomm


*/

//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* trimZeros(Node* head) {
        while(head->next!=NULL && head->data==0) {
            head=head->next;
        }
        return head;
    }
    Node* reverseLL(Node* head) {
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL) {
            Node* nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
       Node*dummyNode = new Node(-1);
       Node*dummy = dummyNode;
       Node* temp1 = num1;
       Node* temp2 = num2; 
       Node* newHead1=reverseLL(temp1);
       Node* newHead2=reverseLL(temp2);

       int carry = 0; 
       while(newHead1 || newHead2){
           int sum = 0; 
           if(newHead1) {
               sum += newHead1->data;
               newHead1=newHead1->next;
           }
           if(newHead2) {
               sum += newHead2->data;
               newHead2=newHead2->next;
           }
           sum += carry ;
           carry = sum /10;
           dummy->next = new Node(sum%10);
           dummy = dummy->next;
       }
       if(carry) {
           dummy->next=new Node(carry);
           dummy=dummy->next;
       }
       return trimZeros(reverseLL(dummyNode->next));
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends