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

        int leftHeight = 0;
        int rightHeight = 0;

        TreeNode *leftParent = root;
        TreeNode *rightParent = root;

        while (leftParent != nullptr)

        {
            leftHeight++;
            leftParent = leftParent->left;
        }

        while (rightParent != nullptr)

        {
            rightHeight++;
            rightParent = rightParent->right;
        }

        if (leftHeight == rightHeight)
            return pow(2, leftHeight) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};