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
    TreeNode *node;

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        DFS(original, cloned, target);
        return node;
    }

    void DFS(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr)
            return;

        getTargetCopy(original->left, cloned->left, target);

        if (original == target)
        {
            node = cloned;
            return;
        }

        getTargetCopy(original->right, cloned->right, target);
    }
};