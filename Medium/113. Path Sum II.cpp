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
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> paths;
        vector<int> currentPath;
        pathSumRecursive(root, sum, currentPath, paths);
        return paths;
    }

    void pathSumRecursive(TreeNode *root, int sum, vector<int> &currentPath, vector<vector<int>> &paths)
    {

        if (root == nullptr)
            return;

        currentPath.push_back(root->val);

        if (root->val == sum && root->left == nullptr && root->right == nullptr)
            paths.push_back(currentPath);

        pathSumRecursive(root->left, sum - root->val, currentPath, paths);
        pathSumRecursive(root->right, sum - root->val, currentPath, paths);
        currentPath.pop_back();
    }
};