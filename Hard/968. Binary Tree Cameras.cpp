// https://leetcode.com/problems/binary-tree-cameras/

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
    int isCovered = 0;
    int cameraIsRequired = 1;
    int hasCamera = 2;

public:
    int minCameraCover(TreeNode *root)
    {
        return dfs(root) == cameraIsRequired ? result + 1 : result;
    }

    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return isCovered;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == cameraIsRequired || right == cameraIsRequired)
        {
            result++;
            return hasCamera;
        }

        if (left == hasCamera || right == hasCamera)
            return isCovered;

        return cameraIsRequired;
    }
};