// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(10);
        DFS(root, freq);
        return result;
    }

    void DFS(TreeNode *root, vector<int> &freq)
    {
        if (root == nullptr)
            return;

        freq[root->val]++;

        if (root->left == nullptr && root->right == nullptr)
            if (isPseudoPalindromic(freq))
                result++;

        DFS(root->left, freq);
        DFS(root->right, freq);
        freq[root->val]--;
    }

    bool isPseudoPalindromic(vector<int> &freq)
    {
        int oddCounter = 0;

        for (int i = 1; i <= 9; ++i)
            if (freq[i] % 2 != 0)
                oddCounter++;

        return oddCounter <= 1;
    }
};