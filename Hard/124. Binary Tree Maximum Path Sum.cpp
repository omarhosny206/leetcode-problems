// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int result = INT_MIN;
    unordered_map<TreeNode *, int> nodeMaxPathSum;

public:
    int maxPathSum(TreeNode *root)
    {
        getNodesMaxPathSum(root);

        dfs(root);

        return result;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (root->left != nullptr && root->right != nullptr)
            result = max({result, nodeMaxPathSum[root], root->val + nodeMaxPathSum[root->left] + nodeMaxPathSum[root->right]});

        else
            result = max(result, nodeMaxPathSum[root]);

        dfs(root->left);
        dfs(root->right);
    }

    int getNodesMaxPathSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = getNodesMaxPathSum(root->left);
        int right = getNodesMaxPathSum(root->right);

        int maxPathValue = max(left, right);

        nodeMaxPathSum[root] = max(root->val, root->val + maxPathValue);
        return nodeMaxPathSum[root];
    }
};