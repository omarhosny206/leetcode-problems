// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    vector<int> result;
    unordered_map<TreeNode *, TreeNode *> parent;

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        if (K == 0)
            return {target->val};

        getParent(root, nullptr);
        getBelowDistanceK(target, K);

        if (root != target)
            getAboveDistanceK(target, K);

        return result;
    }

    void getParent(TreeNode *root, TreeNode *nodeParent)
    {
        if (root == nullptr)
            return;

        parent[root] = nodeParent;
        getParent(root->left, root);
        getParent(root->right, root);
    }

    void getBelowDistanceK(TreeNode *root, int K)
    {
        if (root == nullptr || K < 0)
            return;

        if (K == 0)
            result.push_back(root->val);

        getBelowDistanceK(root->left, K - 1);
        getBelowDistanceK(root->right, K - 1);
    }

    void getAboveDistanceK(TreeNode *root, int K)
    {
        if (root == nullptr || K < 0)
            return;

        if (K == 0)
            result.push_back(root->val);

        if (parent[root] != nullptr)
            parent[root]->left == root ? getBelowDistanceK(parent[root]->right, K - 2) : getBelowDistanceK(parent[root]->left, K - 2);

        getAboveDistanceK(parent[root], K - 1);
    }
};