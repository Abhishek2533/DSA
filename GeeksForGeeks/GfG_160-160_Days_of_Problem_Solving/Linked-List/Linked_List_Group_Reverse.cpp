/*

Company Tags:

        Paytm
        VMWare
        Accolite
        Amazon
        Microsoft
        Snapdeal
        Hike
        MakeMyTrip
        Walmart
        Goldman Sachs
        Adobe
        SAP Labs


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node* reverseLinkedList(Node* head) {
        Node* temp=head;
        Node* prev=NULL;
        
        while(temp!=NULL) {
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        
        return prev;
    }
    Node* getKthNode(Node* temp, int k) {
        k-=1;
        while(temp!=NULL && k>0) {
            k--;
            temp=temp->next;
        }
        
        return temp;
    }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head==NULL || k<=1) return head;
        Node* temp=head;
        Node* prevNode=NULL;
        
        while(temp!=NULL) {
            Node* kthNode=getKthNode(temp, k);
            if(kthNode==NULL) {
                Node* newHead=reverseLinkedList(temp);
                if(prevNode) prevNode->next=newHead;
                break;
            }
            
            Node* nextNode=kthNode->next;
            kthNode->next=NULL;
            
            Node* newHead=reverseLinkedList(temp);
            if(temp==head) head=newHead;
            else prevNode->next=newHead;
            
            prevNode=temp;
            temp=nextNode;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends