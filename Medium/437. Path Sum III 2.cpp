// https://leetcode.com/problems/path-sum-iii/

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
    int numPaths = 0;

public:
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return numPaths;

        countPaths(root, sum);

        return numPaths;
    }

    void countPaths(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return;

        int currentSum = 0;
        DFS(root, currentSum, sum);

        countPaths(root->left, sum);
        countPaths(root->right, sum);
    }
    void DFS(TreeNode *root, int currentSum, int sum)
    {
        if (root == nullptr)
            return;

        currentSum += root->val;

        if (currentSum == sum)
            numPaths++;

        DFS(root->left, currentSum, sum);
        DFS(root->right, currentSum, sum);
    }
};