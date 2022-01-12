// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int sumRootToLeaf(TreeNode *root)
    {
        dfs(root, "");
        return result;
    }

    void dfs(TreeNode *root, string currentPath)
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
            result += toDecimal(currentPath + to_string(root->val));

        currentPath += to_string(root->val);
        dfs(root->left, currentPath);
        dfs(root->right, currentPath);
    }

    int toDecimal(string num)
    {
        int result = 0;
        int power = num.length() - 1;

        for (int i = 0; i < num.length(); ++i)
            result += (num[i] - '0') * pow(2, power--);

        return result;
    }
};