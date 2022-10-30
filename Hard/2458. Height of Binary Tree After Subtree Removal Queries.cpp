// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/

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
    unordered_map<int, int> height;
    unordered_map<int, int> depth;
    unordered_map<int, pair<int, int>> maxHeight;

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        vector<int> result;

        dfs(root, 0);

        for (int &query : queries)
        {
            int value;
            int targetDepth = depth[query];

            if (height[query] == maxHeight[targetDepth].first)
                value = targetDepth + maxHeight[targetDepth].second - 1;

            else
                value = targetDepth + maxHeight[targetDepth].first - 1;

            result.push_back(value);
        }

        return result;
    }

    int dfs(TreeNode *root, int currentDepth)
    {
        if (root == nullptr)
            return 0;

        depth[root->val] = currentDepth;
        int left = dfs(root->left, currentDepth + 1);
        int right = dfs(root->right, currentDepth + 1);
        height[root->val] = max(left, right) + 1;

        if (maxHeight[currentDepth].first < height[root->val])
        {
            maxHeight[currentDepth].second = maxHeight[currentDepth].first;
            maxHeight[currentDepth].first = height[root->val];
        }

        else if (maxHeight[currentDepth].second < height[root->val])
            maxHeight[currentDepth].second = height[root->val];

        return height[root->val];
    }
};