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
    void dfs(Node* root, int sum, int len, int& maxLen, int& maxSum) {
        if (!root) return;
        
        sum += root->data;
        len++;
        
        if (!root->left && !root->right) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
        }

        dfs(root->left, sum, len, maxLen, maxSum);
        dfs(root->right, sum, len, maxLen, maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int maxLen = 0, maxSum = 0;
        dfs(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};