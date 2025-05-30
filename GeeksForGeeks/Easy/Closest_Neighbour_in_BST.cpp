/*
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
}; */

class Solution {
  public:
    void searchInTree(Node* root, int& res, int k) {
        if(!root) return;
        if(root->data<=k) res=max(res, root->data);
        if(root->data < k) searchInTree(root->right, res, k);
        else searchInTree(root->left, res, k);
    }
    
    int findMaxFork(Node* root, int k) {
        // code here
        int res=-1;
        searchInTree(root, res, k);
        return res;
    }
};