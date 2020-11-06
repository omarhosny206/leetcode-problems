// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    priority_queue<int, vector<int>, greater<int>> nodes_minHeap;

    int kthSmallest(TreeNode *root, int k)
    {
        kthSmallest_Helper(root);
        while (k > 1)
        {
            nodes_minHeap.pop();
            k--;
        }

        return nodes_minHeap.top();
    }

    void kthSmallest_Helper(TreeNode *root)
    {
        if (root == nullptr)
            return;
        nodes_minHeap.push(root->val);
        kthSmallest_Helper(root->left);
        kthSmallest_Helper(root->right);
    }
};