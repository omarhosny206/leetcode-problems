// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int sumRootToLeaf(TreeNode *root)
    {
        return sumRootToLeafHelper(root, 0);
    }

    int sumRootToLeafHelper(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;

        sum = (sum << 1) + root->val;

        if (root->left == nullptr && root->right == nullptr)
            return sum;

        return sumRootToLeafHelper(root->left, sum) + sumRootToLeafHelper(root->right, sum);
    }
};
