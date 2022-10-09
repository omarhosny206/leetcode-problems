// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    unordered_set<int> complements;

public:
    bool findTarget(TreeNode *root, int k)
    {
        return dfs(root, k);
    }

    bool dfs(TreeNode *root, int k)
    {
        if (root == nullptr)
            return false;

        if (complements.find(root->val) != complements.end())
            return true;

        complements.insert(k - root->val);

        return dfs(root->left, k) || dfs(root->right, k);
    }
};