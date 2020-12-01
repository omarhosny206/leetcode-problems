// https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
    int answer;

public:
    int distributeCoins(TreeNode *root)
    {
        answer = 0;
        DFS(root);
        return answer;
    }

    int DFS(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = DFS(root->left);
        int right = DFS(root->right);
        answer += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};