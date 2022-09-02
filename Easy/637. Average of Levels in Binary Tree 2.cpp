// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> result;
    vector<pair<int, double>> levels;

public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        dfs(root, 0);

        for (auto &level : levels)
            result.push_back(level.second / level.first);

        return result;
    }

    void dfs(TreeNode *root, int currentLevel)
    {
        if (root == nullptr)
            return;

        if (levels.size() <= currentLevel)
            levels.push_back({});

        levels[currentLevel].first++;
        levels[currentLevel].second += root->val;

        dfs(root->left, currentLevel + 1);
        dfs(root->right, currentLevel + 1);
    }
};