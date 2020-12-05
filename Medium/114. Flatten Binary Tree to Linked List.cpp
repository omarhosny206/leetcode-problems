// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        vector<int> nodes;
        DFS(root, nodes);
        nodes.erase(nodes.begin());

        root->left = nullptr;
        root->right = nullptr;

        TreeNode *current = root;

        for (int val : nodes)
        {
            current->right = new TreeNode(val);
            current = current->right;
        }
    }

    void DFS(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;

        nodes.push_back(root->val);
        DFS(root->left, nodes);
        DFS(root->right, nodes);
    }
};