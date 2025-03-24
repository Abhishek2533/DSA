/*

Company Tags:

        Accolite
        Amazon
        Microsoft


*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends

// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    Node* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& preorder, int preStart, int preEnd, map<int, int>& mpp) {
        if(inStart>inEnd || preStart>preEnd) return NULL;
        Node* root=new Node(preorder[preStart]);
        int inRoot=mpp[root->data];
        int numsLeft = inRoot - inStart;
        
        root->left=buildTreeHelper(inorder, inStart, inRoot-1, preorder, preStart+1, preStart+numsLeft, mpp);
        root->right=buildTreeHelper(inorder, inRoot+1, inEnd, preorder, preStart+numsLeft+1, preEnd, mpp);
        
        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        map<int, int> mpp;
        for(int i=0; i<inorder.size(); i++) mpp[inorder[i]]=i;
        Node* root = buildTreeHelper(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, mpp);
        return root;
    }
};


//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends