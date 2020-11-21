// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string tree2str(TreeNode *t)
    {
        return preOrder(t);
    }

    string preOrder(TreeNode *t)
    {
        if (t == nullptr)
            return "";

        if (t->left == nullptr && t->right == nullptr)
            return to_string(t->val);

        if (t->right == nullptr)
            return to_string(t->val) + "(" + preOrder(t->left) + ")";

        return to_string(t->val) + "(" + preOrder(t->left) + ")(" + preOrder(t->right) + ")";
    }
};