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
        deque<TreeNode *> nodes;

        nodes.push_back(root);

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop_front();

                if (current->left)
                    nodes.push_back(current->left);

                if (current->right)
                    nodes.push_back(current->right);
            }

            if (level % 2 == 0)
            {
                deque<TreeNode *> temp = nodes;

                while (temp.size() > 1)
                {
                    TreeNode *left = temp.front();
                    temp.pop_front();

                    TreeNode *right = temp.back();
                    temp.pop_back();

                    int val = left->val;
                    left->val = right->val;
                    right->val = val;
                }
            }

            level++;
        }

        return root;
    }
};