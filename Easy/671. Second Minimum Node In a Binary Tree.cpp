// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    int findSecondMinimumValue(TreeNode *root)
    {
        set<int> nodes;
        DFS(root, nodes);

        set<int>::iterator itr = nodes.begin();

        if (nodes.size() <= 1)
            return -1;

        return *(++itr);
    }

    void DFS(TreeNode *root, set<int> &nodes)
    {
        if (root == nullptr)
            return;

        nodes.insert(root->val);
        DFS(root->left, nodes);
        DFS(root->right, nodes);
    }
};