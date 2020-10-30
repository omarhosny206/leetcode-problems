// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<string> paths;
        binaryTreePathsRecursive(root, "", paths);

        return paths;
    }

    void binaryTreePathsRecursive(TreeNode *root, string current, vector<string> &paths)
    {
        if (root == nullptr)
            return;

        current = (current.length() == 0) ? to_string(root->val) : current + "->" + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            paths.push_back(current);
            return;
        }
        binaryTreePathsRecursive(root->left, current, paths);
        binaryTreePathsRecursive(root->right, current, paths);
    }
};