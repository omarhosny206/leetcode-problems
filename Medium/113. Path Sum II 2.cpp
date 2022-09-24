// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> paths;

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> currentPath;

        dfs(root, currentPath, targetSum, 0);
        return paths;
    }

    void dfs(TreeNode *root, vector<int> currentPath, int targetSum, int currentSum)
    {

        if (root == nullptr)
            return;

        currentSum += root->val;
        currentPath.push_back(root->val);

        if (currentSum == targetSum && root->left == nullptr && root->right == nullptr)
            paths.push_back(currentPath);

        dfs(root->left, currentPath, targetSum, currentSum);
        dfs(root->right, currentPath, targetSum, currentSum);
    }
};