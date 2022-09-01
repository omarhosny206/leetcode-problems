
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
    int result = 0;

public:
    int goodNodes(TreeNode *root)
    {
        dfs(root, INT_MIN);
        return result;
    }

    void dfs(TreeNode *root, int pathMaxValue)
    {
        if (root == nullptr)
            return;

        pathMaxValue = max(pathMaxValue, root->val);

        if (root->val == pathMaxValue)
            result++;

        dfs(root->left, pathMaxValue);
        dfs(root->right, pathMaxValue);
    }
};