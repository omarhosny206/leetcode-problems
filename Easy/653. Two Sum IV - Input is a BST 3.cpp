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
    bool found = false;
    unordered_set<int> complements;

public:
    bool findTarget(TreeNode *root, int k)
    {
        dfs(root, k);
        return found;
    }

    void dfs(TreeNode *root, int k)
    {
        if (root == nullptr)
            return;

        if (complements.find(k - root->val) != complements.end())
        {
            found = true;
            return;
        }

        complements.insert(root->val);

        if (!found)
        {
            dfs(root->left, k);
            dfs(root->right, k);
        }
    }
};