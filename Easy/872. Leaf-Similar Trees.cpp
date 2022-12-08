// https://leetcode.com/problems/leaf-similar-trees/

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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> firstLeaves;
        vector<int> secondLeaves;

        dfs(root1, firstLeaves);
        dfs(root2, secondLeaves);

        return firstLeaves == secondLeaves;
    }

    void dfs(TreeNode *root, vector<int> &leaves)
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
            leaves.push_back(root->val);

        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }
};