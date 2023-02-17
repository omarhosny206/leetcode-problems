
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
    int result = INT_MAX;
    int previous = -1;

public:
    int minDiffInBST(TreeNode *root)
    {
        dfs(root);
        return result;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        dfs(root->left);

        if (previous != -1)
            result = min(result, abs(root->val - previous));

        previous = root->val;

        dfs(root->right);
    }
};