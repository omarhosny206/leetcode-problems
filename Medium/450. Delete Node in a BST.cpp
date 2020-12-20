// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root;

        if (root->val < key)
            root->right = deleteNode(root->right, key);

        else if (root->val > key)
            root->left = deleteNode(root->left, key);

        else
        {
            if (root->left == nullptr && root->right == nullptr)
                root = nullptr;

            else if (root->left != nullptr)
            {
                root->val = inorderPredecessor(root);
                root->left = deleteNode(root->left, root->val);
            }

            else
            {
                root->val = inorderSuccessor(root);
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }

    int inorderPredecessor(TreeNode *root)
    {
        root = root->left;
        while (root->right)
            root = root->right;
        return root->val;
    }

    int inorderSuccessor(TreeNode *root)
    {
        root = root->right;
        while (root->left)
            root = root->left;
        return root->val;
    }
};