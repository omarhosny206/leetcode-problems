// https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    vector<int> findMode(TreeNode *root)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        int maxFreq = 0;

        DFS(root, freq, maxFreq);

        result = generateValues(freq, maxFreq);

        return result;
    }

    vector<int> generateValues(unordered_map<int, int> &freq, int &maxFreq)
    {
        vector<int> result;

        for (auto pair : freq)
            if (pair.second == maxFreq)
                result.push_back(pair.first);

        return result;
    }

    void DFS(TreeNode *root, unordered_map<int, int> &freq, int &maxFreq)
    {
        if (root == nullptr)
            return;

        freq[root->val]++;
        maxFreq = max(maxFreq, freq[root->val]);
        DFS(root->left, freq, maxFreq);
        DFS(root->right, freq, maxFreq);
    }
};