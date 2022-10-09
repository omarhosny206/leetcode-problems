// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    unordered_set<int> complements;

public:
    bool findTarget(TreeNode *root, int k)
    {
        return bfs(root, k);
    }

    bool bfs(TreeNode *root, int k)
    {
        if (root == nullptr)
            return false;

        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                if (complements.find(current->val) != complements.end())
                    return true;

                complements.insert(k - current->val);

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }
        }

        return false;
    }
};