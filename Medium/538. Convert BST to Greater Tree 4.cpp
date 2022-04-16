// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    TreeNode *convertBST(TreeNode *root)
    {
        vector<int> postfixSum;
        int i = 0;

        insertPostfixSum(root, postfixSum);
        return dfs(root, postfixSum, i);
    }

    TreeNode *dfs(TreeNode *root, vector<int> &postfixSum, int &i)
    {
        if (root == nullptr)
            return nullptr;

        root->left = dfs(root->left, postfixSum, i);

        root->val = postfixSum[postfixSum.size() - i - 1];
        i++;

        root->right = dfs(root->right, postfixSum, i);

        return root;
    }

    void insertPostfixSum(TreeNode *root, vector<int> &postfixSum)
    {
        if (root == nullptr)
            return;

        insertPostfixSum(root->right, postfixSum);
        (postfixSum.size() == 0) ? postfixSum.push_back(root->val) : postfixSum.push_back(root->val + postfixSum.back());
        insertPostfixSum(root->left, postfixSum);
    }
};