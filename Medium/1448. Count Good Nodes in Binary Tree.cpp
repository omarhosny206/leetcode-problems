// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int goodNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int max = root->val;
        DFS(root, max);

        return result;
    }

    void DFS(TreeNode *root, int max)
    {
        if (root == nullptr)
            return;

        if (root->val >= max)
        {
            result++;
            max = root->val;
        }

        DFS(root->left, max);
        DFS(root->right, max);
    }
};