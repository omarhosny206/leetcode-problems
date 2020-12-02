// https://leetcode.com/problems/even-odd-tree/

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
    bool isEvenOddTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return BFS(root);
    }

    bool BFS(TreeNode *root)
    {

        queue<TreeNode *> nodes;
        nodes.push(root);

        int level = true;

        while (!nodes.empty())
        {
            int size = nodes.size();
            int max = INT_MAX;
            int min = INT_MIN;

            for (int i = 0; i < size; i++)
            {

                if (level)
                {
                    TreeNode *current = nodes.front();
                    nodes.pop();

                    if (current->val % 2 == 0 || current->val <= min)
                        return false;

                    min = current->val;

                    if (current->left)
                        nodes.push(current->left);

                    if (current->right)
                        nodes.push(current->right);
                }

                else
                {
                    TreeNode *current = nodes.front();
                    nodes.pop();

                    if (current->val % 2 == 1 || current->val >= max)
                        return false;

                    max = current->val;

                    if (current->left)
                        nodes.push(current->left);

                    if (current->right)
                        nodes.push(current->right);
                }
            }

            level ^= true;
        }

        return true;
    }
};