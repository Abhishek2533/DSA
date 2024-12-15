/*

993. Cousins in Binary Tree

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
Two nodes of a binary tree are cousins if they have the same depth with different parents.
Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.


Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


Constraints:
The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int xDepth, yDepth, xParent, yParent;

    void solveCousins(TreeNode* root, int x, int y, int depth, int parent_val) {
        if(root==NULL) return;

        if(root->val == x) {
            xDepth=depth;
            xParent=parent_val;
            return;
        }

        if(root->val == y) {
            yDepth=depth;
            yParent=parent_val;
            return;
        }

        solveCousins(root->left, x, y, depth+1, root->val);
        solveCousins(root->right, x, y, depth+1, root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) return false;
        solveCousins(root, x, y, 0, 0);

        if(xParent != yParent && xDepth == yDepth) return true;
        return false;
    }
};