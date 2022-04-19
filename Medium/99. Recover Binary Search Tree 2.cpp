
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
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *previous = nullptr;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;

        dfs(root, previous, first, second);
        swap(first->val, second->val);
    }

    void dfs(TreeNode *root, TreeNode *&previous, TreeNode *&first, TreeNode *&second)
    {
        if (root == nullptr)
            return;

        dfs(root->left);

        if (previous != nullptr && previous->val > root->val)
        {
            if (first == nullptr)
                first = previous;

            second = root;
        }

        previous = root;

        dfs(root->right);
    }
};