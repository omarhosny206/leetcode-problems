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
    int result = 0;
    int seen[1001];

public:
    int pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return result;

        seen[0] = 0;

        DFS(root, 0, 1, sum);

        return result;
    }

    void DFS(TreeNode *root, int currentSum, int position, int sum)
    {
        if (root == nullptr)
            return;

        currentSum += root->val;

        for (int i = 0; i < position; i++)
            if (seen[i] == currentSum - sum)
                result++;

        seen[position] = currentSum;

        if (root->left)
            DFS(root->left, currentSum, position + 1, sum);

        if (root->right)
            DFS(root->right, currentSum, position + 1, sum);
    }
};