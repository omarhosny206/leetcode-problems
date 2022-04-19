
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
class Solution
{
    bool isValidBST = true;

public:
    void recoverTree(TreeNode *root)
    {
        isValidBST = false;

        while (!isValidBST)
        {
            isValidBST = true;
            dfs(root, new TreeNode(INT_MAX), new TreeNode(INT_MIN));
        }
    }

    void dfs(TreeNode *root, TreeNode *maxNode, TreeNode *minNode)
    {
        if (root == nullptr)
            return;

        dfs(root->left, root, minNode);

        if (root->val > maxNode->val)
        {
            isValidBST = false;
            int temp = root->val;
            root->val = maxNode->val;
            maxNode->val = temp;
        }

        else if (root->val < minNode->val)
        {
            isValidBST = false;
            int temp = root->val;
            root->val = minNode->val;
            minNode->val = temp;
        }

        dfs(root->right, maxNode, root);
    }
};