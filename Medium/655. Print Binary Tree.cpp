// https://leetcode.com/problems/print-binary-tree/

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
    vector<vector<string>> printTree(TreeNode *root)
    {
        vector<vector<string>> result;

        int depth = getDepth(root);
        int rows = depth;
        int columns = pow(2, depth) - 1;

        result = vector<vector<string>>(depth, vector<string>(columns));

        DFS(root, result, 0, 0, columns - 1);

        return result;
    }

    void DFS(TreeNode *root, vector<vector<string>> &result, int i, int start, int end)
    {
        if (root == nullptr)
            return;

        int middle = start + (end - start) / 2;
        result[i][middle] = to_string(root->val);

        DFS(root->left, result, i + 1, start, middle - 1);
        DFS(root->right, result, i + 1, middle + 1, end);
    }

    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = getDepth(root->left);
        int right = getDepth(root->right);

        return 1 + max(left, right);
    }
};