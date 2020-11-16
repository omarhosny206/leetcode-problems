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
    priority_queue<int, vector<int>, greater<int>> nodes;

public:
    BSTIterator(TreeNode *root)
    {
        DFS(root);
    }

    int next()
    {
        int top = nodes.top();
        nodes.pop();
        return top;
    }

    bool hasNext()
    {
        return !nodes.empty();
    }

    void DFS(TreeNode *root)
    {
        if (root == nullptr)
            return;
        nodes.push(root->val);
        DFS(root->left);
        DFS(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */