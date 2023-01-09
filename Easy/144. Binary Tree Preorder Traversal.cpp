// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<int> result;
        stack<TreeNode *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode *current = nodes.top();
            nodes.pop();

            result.push_back(current->val);

            if (current->right != nullptr)
                nodes.push(current->right);

            if (current->left != nullptr)
                nodes.push(current->left);
        }

        return result;
    }
};