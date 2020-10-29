// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int sumEvenGrandparent(TreeNode *root)
    {
        sumEvenGrandparentRecursive(root, 1, 1);
        return sum;
    }

    void sumEvenGrandparentRecursive(TreeNode *current, int parentVal, int grandParentVal)
    {

        if (current == nullptr)
            return;

        if (grandParentVal % 2 == 0)
        {
            sum += current->val;
        }

        sumEvenGrandparentRecursive(current->left, current->val, parentVal);
        sumEvenGrandparentRecursive(current->right, current->val, parentVal);
    }
};