// https://leetcode.com/problems/delete-leaves-with-a-given-value/

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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        return DFS(root, target);
    }

    TreeNode *DFS(TreeNode *root, int target)
    {
        if (root == nullptr)
            return nullptr;

        root->left = DFS(root->left, target);
        root->right = DFS(root->right, target);

        if (root->val == target && root->left == nullptr && root->right == nullptr)
            return nullptr;

        return root;
    }
};