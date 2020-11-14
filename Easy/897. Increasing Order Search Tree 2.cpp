// https://leetcode.com/problems/increasing-order-search-tree/

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
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        vector<int> nodes;
        DFS(root, nodes);
        root = treeBuilder(nodes);
        return root;
    }

    void DFS(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;

        DFS(root->left, nodes);
        nodes.push_back(root->val);
        DFS(root->right, nodes);
    }

    TreeNode *treeBuilder(vector<int> &nodes)
    {

        if (nodes.empty())
            return nullptr;

        TreeNode *root = new TreeNode(nodes.front());
        nodes.erase(nodes.begin());
        root->right = treeBuilder(nodes);
        return root;
    }
};