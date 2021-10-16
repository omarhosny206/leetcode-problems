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

            if (current->left != nullptr)
                nodes.push(current->left);

            if (current->right != nullptr)
                nodes.push(current->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};