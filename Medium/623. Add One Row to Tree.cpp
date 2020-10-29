// https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        if (d == 1)
        {
            TreeNode *newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        }
        addOneRowRecursive(root, v, d, 1);
        return root;
    }

    void addOneRowRecursive(TreeNode *root, int v, int d, int Depth)
    {

        if (root == nullptr)
            return;

        if (Depth == d - 1)
        {
            TreeNode *leftNodes = root->left;
            TreeNode *rightNodes = root->right;
            root->left = new TreeNode(v);
            root->right = new TreeNode(v);
            root->left->left = leftNodes;
            root->right->right = rightNodes;
        }

        addOneRowRecursive(root->left, v, d, Depth + 1);
        addOneRowRecursive(root->right, v, d, Depth + 1);
    }
};