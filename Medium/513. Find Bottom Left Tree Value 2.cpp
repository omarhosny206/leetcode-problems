// https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int requiredTreeNode;
    int maxDepth = 0;

public:
    int findBottomLeftValue(TreeNode *root)
    {
        requiredTreeNode = root->val;
        BFS(root);
        return requiredTreeNode;
    }

    int BFS(TreeNode *root)
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

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }

            if (!nodes.empty())
                requiredTreeNode = nodes.front()->val;
        }

        return requiredTreeNode;
    }
};