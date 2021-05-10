// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode *root)
    {

        vector<int> post_order_vals;
        stack<TreeNode *> curr;

        if (root == nullptr)
            return post_order_vals;

        curr.push(root);
        while (!curr.empty())
        {
            TreeNode *current_node = curr.top();
            curr.pop();
            int val = current_node->val;
            post_order_vals.push_back(val);

            if (current_node->left != nullptr)
                curr.push(current_node->left);

            if (current_node->right != nullptr)
                curr.push(current_node->right);
        }
        reverse(post_order_vals.begin(), post_order_vals.end());
        return post_order_vals;
    }
};