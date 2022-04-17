
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

        return buildTree(nodes);
    }

    void dfs(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;

        dfs(root->left, nodes);
        nodes.push_back(root->val);
        dfs(root->right, nodes);
    }

    TreeNode *buildTree(vector<int> &nodes)
    {
        TreeNode *result = new TreeNode();
        TreeNode *current = result;

        int i = 0;

        while (i < nodes.size())
        {
            current->right = new TreeNode(nodes[i]);
            current = current->right;
            i++;
        }

        return result->right;
    }
};