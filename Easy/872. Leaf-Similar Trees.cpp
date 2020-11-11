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
        vector<int> firstNodes;
        vector<int> secondNodes;
        DFS(root1, firstNodes);
        DFS(root2, secondNodes);
        return firstNodes == secondNodes;
    }

    void DFS(TreeNode *root, vector<int> &nodes)
    {

        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
        {
            nodes.push_back(root->val);
            return;
        }

        DFS(root->left, nodes);
        DFS(root->right, nodes);
    }
};