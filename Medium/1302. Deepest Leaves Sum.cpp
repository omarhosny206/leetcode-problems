// https://leetcode.com/problems/deepest-leaves-sum/

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
    int maxDepth = 0;
    map<int, int> nodeDepth;

public:
    int deepestLeavesSum(TreeNode *root)
    {
        deepestLeavesSumRecursive(root, 0);

        for (pair<int, int> p : nodeDepth)
            sum += p.first;

        return sum;
    }

    void deepestLeavesSumRecursive(TreeNode *current, int depth)
    {
        if (current == nullptr)
            return;

        if (maxDepth < depth)
            nodeDepth.clear();

        maxDepth = max(maxDepth, depth);

        if (current->left == nullptr && current->right == nullptr && depth >= maxDepth)
            nodeDepth[current->val] = depth;

        if (current->left)
            deepestLeavesSumRecursive(current->left, depth + 1);

        if (current->right)
            deepestLeavesSumRecursive(current->right, depth + 1);
    }
};