// https://leetcode.com/problems/binary-tree-tilt/

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
    int totalTilt = 0;

public:
    int findTilt(TreeNode *root)
    {
        Helper(root);
        return totalTilt;
    }

    int Helper(TreeNode *root)
    {

        if (root == nullptr)
            return 0;

        int left = Helper(root->left);
        int right = Helper(root->right);
        int tilt = abs(left - right);
        totalTilt += tilt;

        return root->val + left + right;
    }
};