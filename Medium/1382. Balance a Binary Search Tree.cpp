// https://leetcode.com/problems/balance-a-binary-search-tree/

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
    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        vector<TreeNode *> nodes;
        inOrder(root, nodes);
        return BinarySearchBuilder(nodes, 0, nodes.size() - 1);
    }

    void inOrder(TreeNode *root, vector<TreeNode *> &nodes)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, nodes);
        nodes.push_back(root);
        inOrder(root->right, nodes);
    }

    TreeNode *BinarySearchBuilder(vector<TreeNode *> &nodes, int start, int end)
    {
        if (start > end)
            return nullptr;

        int middle = (start + end) / 2;
        TreeNode *root = nodes[middle];
        root->left = BinarySearchBuilder(nodes, start, middle - 1);
        root->right = BinarySearchBuilder(nodes, middle + 1, end);
        return root;
    }
};