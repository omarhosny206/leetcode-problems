// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        int level = 0;
        queue<TreeNode *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();
            vector<int> values(pow(2, level + 1));

            int j = 0;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                if (current->left)
                {
                    nodes.push(current->left);
                    values[j++] = current->left->val;
                }

                if (current->right)
                {
                    nodes.push(current->right);
                    values[j++] = current->right->val;
                }
            }

            if (!nodes.empty())
            {
                size = nodes.size();
                j = size - 1;

                for (int i = 0; i < size; ++i)
                {
                    TreeNode *current = nodes.front();
                    nodes.pop();

                    current->val = values[j--];

                    if (current->left)
                        nodes.push(current->left);

                    if (current->right)
                        nodes.push(current->right);
                }
            }

            level += 2;
        }

        return root;
    }
};