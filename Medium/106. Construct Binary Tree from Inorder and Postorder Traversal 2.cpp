// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return treeBuilder(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }

    TreeNode *treeBuilder(vector<int> &inorder, vector<int> &postorder, int iStart, int iEnd, int pIndex)
    {
        if (iStart > iEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[pIndex]);

        int iIndex = iStart;

        while (postorder[pIndex] != inorder[iIndex])
            iIndex++;

        root->left = treeBuilder(inorder, postorder, iStart, iIndex - 1, pIndex - (iEnd - iIndex) - 1);
        root->right = treeBuilder(inorder, postorder, iIndex + 1, iEnd, pIndex - 1);
        return root;
    }
};