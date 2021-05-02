// https://leetcode.com/problems/find-leaves-of-binary-tree/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        DFS(root);
        return result;
    }

    int DFS(TreeNode *root)
    {
        if (root == nullptr)
            return -1;

        int depth = max(DFS(root->left), DFS(root->right)) + 1;

        if (result.size() <= depth)
            result.push_back({});

        result[depth].push_back(root->val);

        return depth;
    }
};