// https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/

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
    TreeNode *findNearestRightNode(TreeNode *root, TreeNode *u)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *result = BFS(root, u);
        return result;
    }

    TreeNode *BFS(TreeNode *root, TreeNode *target)
    {
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                if (current->val == target->val)
                {
                    if (i == size - 1)
                        return nullptr;

                    return nodes.front();
                }

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }
        }

        return nullptr;
    }
};