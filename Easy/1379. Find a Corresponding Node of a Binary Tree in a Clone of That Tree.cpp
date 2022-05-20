// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
    TreeNode *result;

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        dfs(original, cloned, target);
        return result;
    }

    void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr)
            return;

        if (original == target)
        {
            result = cloned;
            return;
        }

        dfs(original->left, cloned->left, target);
        dfs(original->right, cloned->right, target);
    }
};