
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
    int maxDepth(TreeNode *root)
    {
        return dfs(root, 0);
    }

    int dfs(TreeNode *root, int currentDepth)
    {
        if (root == nullptr)
            return depth;

        return max(dfs(root->left, currentDepth + 1), dfs(root->right, currentDepth + 1));
    }
};