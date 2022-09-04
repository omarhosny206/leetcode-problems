// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> result;
    map<int, vector<pair<int, int>>> nodes;

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);

        for (auto &pair : nodes)
        {
            vector<int> current;
            sort(pair.second.begin(), pair.second.end(), compare);

            for (auto &values : nodes[pair.first])
                current.push_back(values.second);

            result.push_back(current);
        }

        return result;
    }

    void dfs(TreeNode *root, int row, int column)
    {
        if (root == nullptr)
            return;

        nodes[column].push_back({row, root->val});
        dfs(root->left, row + 1, column - 1);
        dfs(root->right, row + 1, column + 1);
    }

    static bool compare(pair<int, int> &firstPair, pair<int, int> &secondPair)
    {
        return (firstPair.first < secondPair.first) || (firstPair.first == secondPair.first && firstPair.second < secondPair.second);
    }
};