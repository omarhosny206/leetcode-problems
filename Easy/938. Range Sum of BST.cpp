// https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        rangeSumBST_Recursive(root, low, R);
        return result;
    }

    void rangeSumBST_Recursive(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return;

        if (root->val >= low && root->val <= high)
            sum += root->val;

        if (root->val >= low)
            rangeSumBST_Recursive(root->left, low, high);

        if (root->val <= high)
            rangeSumBST_Recursive(root->right, low, high);
    }
};