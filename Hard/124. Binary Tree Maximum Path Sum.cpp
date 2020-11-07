// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode *root)
    {
        int max_val = INT_MIN;
        maxPathSum_Helper(root, max_val);
        return max_val;
    }

    int maxPathSum_Helper(TreeNode *root, int &max_val)
    {
        if (root == nullptr)
            return 0;
        int left = maxPathSum_Helper(root->left, max_val);
        int right = maxPathSum_Helper(root->right, max_val);
        int whole_path = root->val + left + right;
        int result = max(max(left, right) + root->val, root->val);
        max_val = max(max_val, max(whole_path, result));
        return result;
    }
};