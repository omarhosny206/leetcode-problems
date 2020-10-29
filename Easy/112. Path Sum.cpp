// https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode *root, int sum)
    {

        if (root == nullptr)
            return false;

        else if (root->left == nullptr && root->right == nullptr && sum - root->val == 0)
            return true;

        else
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
