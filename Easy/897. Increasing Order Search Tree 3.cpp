
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
        vector<int> nodes;
        dfs(root, nodes);

        if (nodes.size() == 0)
            return nullptr;

        return buildTree(nodes, 0);
    }

    void dfs(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;

        dfs(root->left, nodes);
        nodes.push_back(root->val);
        dfs(root->right, nodes);
    }

    TreeNode *buildTree(vector<int> &nodes, int i)
    {
        if (i == nodes.size())
            return nullptr;

        TreeNode *root = new TreeNode(nodes[i]);
        root->right = buildTree(nodes, i + 1);
        return root;
    }
};