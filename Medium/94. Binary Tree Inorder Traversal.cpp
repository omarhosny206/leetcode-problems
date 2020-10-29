// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode *root)
    {

        stack<TreeNode *> curr;

        vector<int> in_order_vals;

        while (!curr.empty() || root != nullptr)
        {

            while (root != nullptr)
            {
                curr.push(root);
                root = root->left;
            }

            root = curr.top();
            curr.pop();
            in_order_vals.push_back(root->val);
            root = root->right;
        }
        return in_order_vals;
    }
};