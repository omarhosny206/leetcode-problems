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
    vector<int> freq;

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        freq = vector<int>(10);
        dfs(root);
        return result;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        freq[root->val]++;

        if (root->left == nullptr && root->right == nullptr && isPseudoPalindromic())
            result++;

        dfs(root->left);
        dfs(root->right);

        freq[root->val]--;
    }

    bool isPseudoPalindromic()
    {
        int numOdds = 0;

        for (int &value : freq)
        {
            if (value % 2 != 0)
                numOdds++;

            if (numOdds > 1)
                return false;
        }

        return true;
    }
};