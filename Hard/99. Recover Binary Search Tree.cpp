// https://leetcode.com/problems/recover-binary-search-tree/

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
    void recoverTree(TreeNode *root)
    {
        TreeNode *previous = nullptr, *first = nullptr, *second = nullptr;

        Inorder(root, previous, first, second);

        swap(first->val, second->val);
    }

    void Inorder(TreeNode *root, TreeNode *&previous, TreeNode *&first, TreeNode *&second)
    {
        if (root == nullptr)
            return;

        Inorder(root->left, previous, first, second);

        if (previous != nullptr && root->val < previous->val)
        {
            if (first == nullptr)
                first = previous;

            second = root;
        }

        previous = root;

        Inorder(root->right, previous, first, second);
    }
};