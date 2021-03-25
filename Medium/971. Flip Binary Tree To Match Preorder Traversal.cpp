// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

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
    vector<int> result;
    int pos = 0;

public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        return DFS(root, voyage) == true ? result : vector<int>(1, -1);
    }

    bool DFS(TreeNode *root, vector<int> &voyage)
    {
        if (root == nullptr)
            return true;

        if (root->val != voyage[pos++])
            return false;

        if (root->left && root->left->val != voyage[pos])
        {
            result.push_back(root->val);
            return DFS(root->right, voyage) && DFS(root->left, voyage);
        }

        return DFS(root->left, voyage) && DFS(root->right, voyage);
    }
};