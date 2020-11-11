// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    int min_difference = INT_MAX;
    int prev_node = -1;

public:
    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root);
        return min_difference;
    }

    void inOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inOrder(root->left);
        if (prev_node != -1)
            min_difference = min(min_difference, abs(root->val - prev_node));
        prev_node = root->val;
        inOrder(root->right);
    }
};