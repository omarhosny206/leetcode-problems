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

        vector<int> pre_order_vals;
        stack<TreeNode *> node_stack;

        if (root == nullptr)
            return pre_order_vals;

        node_stack.push(root);
        while (!node_stack.empty())
        {
            TreeNode *current_node = node_stack.top();
            node_stack.pop();

            pre_order_vals.push_back(current_node->val);

            if (current_node->right != nullptr)
                node_stack.push(current_node->right);

            if (current_node->left != nullptr)
                node_stack.push(current_node->left);
        }
        return pre_order_vals;
    }
};