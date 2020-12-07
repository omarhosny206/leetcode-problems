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
public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> complement;
        return DFS(root, complement, k);
    }

    bool DFS(TreeNode *root, unordered_set<int> &complement, int k)
    {
        if (root == nullptr)
            return false;

        if (complement.find(root->val) != complement.end())
            return true;

        complement.insert(k - root->val);

        return DFS(root->left, complement, k) || DFS(root->right, complement, k);
    }
};