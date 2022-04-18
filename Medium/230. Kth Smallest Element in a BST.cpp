// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root, k);
        return result;
    }

    void dfs(TreeNode *root, int &k)
    {
        if (root == nullptr)
            return;

        dfs(root->left, k);

        k--;
        if (k == 0)
        {
            result = root->val;
            return;
        }

        dfs(root->right, k);
    }
};