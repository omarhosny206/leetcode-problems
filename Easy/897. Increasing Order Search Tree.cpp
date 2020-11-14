// https://leetcode.com/problems/increasing-order-search-tree/

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
    TreeNode *increasingBST(TreeNode *root)
    {
        priority_queue<int, vector<int>, greater<int>> nodes_minHeap;
        DFS(root, nodes_minHeap);
        root = treeBuilder(nodes_minHeap);
        return root;
    }

    void DFS(TreeNode *root, priority_queue<int, vector<int>, greater<int>> &nodes_minHeap)
    {
        if (root == nullptr)
            return;
        nodes_minHeap.push(root->val);
        DFS(root->left, nodes_minHeap);
        DFS(root->right, nodes_minHeap);
    }

    TreeNode *treeBuilder(priority_queue<int, vector<int>, greater<int>> nodes_minHeap)
    {

        if (nodes_minHeap.empty())
            return nullptr;

        TreeNode *root = new TreeNode(nodes_minHeap.top());
        nodes_minHeap.pop();
        root->right = treeBuilder(nodes_minHeap);
        return root;
    }
};