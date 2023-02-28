// https://leetcode.com/problems/find-duplicate-subtrees/

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
    vector<TreeNode *> result;
    unordered_map<string, int> freq;

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        dfs(root);
        return result;
    }

    string dfs(TreeNode *root)
    {
        if (!root)
            return "null";

        string left = dfs(root->left);
        string right = dfs(root->right);

        string subtree = to_string(root->val) + "," + left + "," + right;
        freq[subtree]++;

        if (freq[subtree] == 2)
            result.push_back(root);

        return subtree;
    }
};