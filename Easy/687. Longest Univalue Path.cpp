// https://leetcode.com/problems/longest-univalue-path/submissions/

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
    int length = INT_MIN;

public:
    int longestUnivaluePath(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        longestUnivaluePathHelper(root, root->val);
        return length;
    }

    int longestUnivaluePathHelper(TreeNode *root, int value)
    {
        if (root == nullptr)
            return 0;

        int left_path = longestUnivaluePathHelper(root->left, root->val);
        int right_path = longestUnivaluePathHelper(root->right, root->val);
        length = max(length, left_path + right_path);

        if (root->val == value)
            return max(left_path, right_path) + 1;

        return 0;
    }
};