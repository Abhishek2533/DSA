/*

653. Two Sum IV - Input is a BST


Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.


Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false


Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

*/

// SOURCE CODE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class BSTIterator
{
public:
    stack<TreeNode *> myStack;
    bool reverse = true;

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            myStack.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = myStack.top();
        myStack.pop();
        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->val;
    }

    bool hasNext() { return !myStack.empty(); }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};
