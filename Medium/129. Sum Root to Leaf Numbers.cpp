// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sum = 0;

public:
    int sumNumbers(TreeNode *root)
    {
        sumNumbersRecursive(root, 0);
        return sum;
    }

    void sumNumbersRecursive(TreeNode *root, int current_sum)
    {

        if (root == nullptr)
            return;

        current_sum = (current_sum * 10) + root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            sum += current_sum;
            return;
        }

        sumNumbersRecursive(root->left, current_sum);
        sumNumbersRecursive(root->right, current_sum);
    }
};