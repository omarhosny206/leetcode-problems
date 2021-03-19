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
public:
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        return rangeSumBST_Recursive(root, L, R);
    }

    int rangeSumBST_Recursive(TreeNode *root, int L, int R)
    {
        if (root == nullptr)
            return 0;

        int sum = 0;
        if (root->val >= L && root->val <= R)
            sum += root->val;

        return sum + rangeSumBST_Recursive(root->left, L, R) + rangeSumBST_Recursive(root->right, L, R);
    }
};