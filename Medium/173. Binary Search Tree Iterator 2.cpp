// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator
{
    vector<int> nodes;
    int i = 0;

public:
    BSTIterator(TreeNode *root)
    {
        dfs(root);
    }

    int next()
    {
        return nodes[i++];
    }

    bool hasNext()
    {
        return i < nodes.size();
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        dfs(root->left);
        nodes.push_back(root->val);
        dfs(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */