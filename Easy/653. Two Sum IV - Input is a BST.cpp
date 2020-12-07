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
public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> complement;
        return BFS(root, complement, k);
    }

    bool BFS(TreeNode *root, unordered_set<int> &complement, int k)
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

                if (complement.find(current->val) != complement.end())
                    return true;

                complement.insert(k - current->val);

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }
        }

        return false;
    }
};