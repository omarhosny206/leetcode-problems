// https://leetcode.com/problems/delete-nodes-and-return-forest/

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

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        DFS(root, to_delete);

        if (root)
            result.push_back(root);

        return result;
    }

    void DFS(TreeNode *&root, vector<int> &to_delete)
    {
        if (root == NULL)
            return;

        DFS(root->left, to_delete);
        DFS(root->right, to_delete);

        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end())
        {
            if (root->left)
                result.push_back(root->left);

            if (root->right)
                result.push_back(root->right);

            root = nullptr;
        }
    }
};