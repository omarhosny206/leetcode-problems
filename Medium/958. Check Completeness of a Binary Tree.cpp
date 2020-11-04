// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    bool isCompleteTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        bool end = false;
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode *current = nodes.front();
            nodes.pop();

            if (current == nullptr)
                end = true;

            else
            {
                if (end)
                    return false;
                nodes.push(current->left);
                nodes.push(current->right);
            }
        }
        return true;
    }
};