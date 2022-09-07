// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string result = "";

public:
    string tree2str(TreeNode *root)
    {
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode *root, int i)
    {
        if (root == nullptr)
            return;

        result += to_string(root->val);

        if (root->left)
        {
            result += "(";
            dfs(root->left, i + 1);
        }

        else if (root->right != nullptr)
            result += "()";

        if (root->right)
        {
            result += "(";
            dfs(root->right, i + 1);
        }

        if (i != 0)
            result += ")";
    }
};