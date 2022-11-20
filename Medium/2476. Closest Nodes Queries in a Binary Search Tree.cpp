// https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/

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
    vector<int> values;
    bool found = false;

public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<vector<int>> result;

        dfs(root);

        for (int &query : queries)
        {
            found = false;
            int index = binarySearch(query);

            if (found == true)
                result.push_back({values[index], values[index]});

            else
            {
                if (index == 0)
                    result.push_back({-1, values[index]});

                else if (index == values.size())
                    result.push_back({values[values.size() - 1], -1});

                else
                    result.push_back({values[index - 1], values[index]});
            }
        }

        return result;
    }

    int binarySearch(int &target)
    {
        int left = 0;
        int right = values.size() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (values[middle] == target)
            {
                found = true;
                return middle;
            }

            if (values[middle] < target)
                left = middle + 1;

            else
                right = middle - 1;
        }

        found = false;
        return left;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        dfs(root->left);
        values.push_back(root->val);
        dfs(root->right);
    }
};