// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    map<int, int> nodeIndex;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
            nodeIndex[inorder[i]] = i;

        return treeBuilder(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode *treeBuilder(vector<int> &preorder, vector<int> &inorder, int pStart, int iStart, int iEnd)
    {
        if (pStart >= preorder.size() || iStart > iEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[pStart]);
        root->left = treeBuilder(preorder, inorder, pStart + 1, iStart, nodeIndex[root->val] - 1);
        root->right = treeBuilder(preorder, inorder, pStart + 1 + nodeIndex[root->val] - iStart, nodeIndex[root->val] + 1, iEnd);

        return root;
    }
};