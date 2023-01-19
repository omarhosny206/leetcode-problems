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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (k == 0)
            return {target->val};

        getParent(root, nullptr);
        getBelowNodesWithDistanceK(target, k);

        if (root != target)
            getAboveNodesWithDistanceK(target, k);

        return result;
    }

    void getAboveNodesWithDistanceK(TreeNode *root, int k)
    {
        if (root == nullptr || k < 0)
            return;

        if (k == 0)
        {
            result.push_back(root->val);
            return;
        }

        if (parent[root] != nullptr)
        {
            if (parent[root]->left == root)
                getBelowNodesWithDistanceK(parent[root]->right, k - 2);

            else
                getBelowNodesWithDistanceK(parent[root]->left, k - 2);
        }

        getAboveNodesWithDistanceK(parent[root], k - 1);
    }

    void getBelowNodesWithDistanceK(TreeNode *root, int k)
    {
        if (root == nullptr || k < 0)
            return;

        if (k == 0)
        {
            result.push_back(root->val);
            return;
        }

        getBelowNodesWithDistanceK(root->left, k - 1);
        getBelowNodesWithDistanceK(root->right, k - 1);
    }

    void getParent(TreeNode *root, TreeNode *node)
    {
        if (root == nullptr)
            return;

        parent[root] = node;

        getParent(root->left, root);
        getParent(root->right, root);
    }
};