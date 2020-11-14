// https://leetcode.com/problems/cousins-in-binary-tree/

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
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == nullptr)
            return false;

        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();
            bool isXExist = false;
            bool isYExist = false;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                if (current->val == x)
                    isXExist = true;

                if (current->val == y)
                    isYExist = true;

                if (current->left != nullptr && current->right != nullptr)
                {
                    if (current->left->val == x && current->right->val == y)
                        return false;

                    if (current->left->val == y && current->right->val == x)
                        return false;
                }

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }

            if (isXExist && isYExist)
                return true;
        }

        return false;
    }
};