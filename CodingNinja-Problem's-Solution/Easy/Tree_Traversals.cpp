/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inorder(TreeNode *node, vector<int> &ans1)
{
    if (node == NULL)
        return;
    inorder(node->left, ans1);
    ans1.push_back(node->data);
    inorder(node->right, ans1);
}

void preorder(TreeNode *node, vector<int> &ans2)
{
    if (node == NULL)
        return;
    ans2.push_back(node->data);
    preorder(node->left, ans2);
    preorder(node->right, ans2);
}

void postorder(TreeNode *node, vector<int> &ans3)
{
    if (node == NULL)
        return;
    postorder(node->left, ans3);
    postorder(node->right, ans3);
    ans3.push_back(node->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans1;
    vector<int> ans2;
    vector<int> ans3;

    inorder(root, ans1);
    preorder(root, ans2);
    postorder(root, ans3);

    return {ans1, ans2, ans3};
}