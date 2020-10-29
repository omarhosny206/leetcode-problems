// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode *root)
    {

        if (root == nullptr)
            return 0;

        int left_height = 0, right_height = 0;

        TreeNode *left_parent = root;
        TreeNode *right_parent = root;

        while (left_parent != nullptr)
        {

            left_height++;
            left_parent = left_parent->left;
        }

        while (right_parent != nullptr)
        {

            right_height++;
            right_parent = right_parent->right;
        }

        if (left_height == right_height)
            return pow(2, left_height) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};