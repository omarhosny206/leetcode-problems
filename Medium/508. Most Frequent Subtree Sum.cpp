// https://leetcode.com/problems/most-frequent-subtree-sum/

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
    int maxFreq = 0;

public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        DFS(root, freq);

        for (auto pair : freq)
            if (pair.second == maxFreq)
                result.push_back(pair.first);

        return result;
    }

    int DFS(TreeNode *root, unordered_map<int, int> &freq)
    {
        if (root == nullptr)
            return 0;

        int left = DFS(root->left, freq);
        int right = DFS(root->right, freq);

        int sum = root->val + left + right;
        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);

        return sum;
    }
};