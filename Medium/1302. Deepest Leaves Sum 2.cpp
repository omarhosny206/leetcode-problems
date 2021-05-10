//https://leetcode.com/problems/deepest-leaves-sum/

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
    int deepestLeavesSum(TreeNode *root)
    {
        int level_sum = 0;
        queue<TreeNode *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            level_sum = 0;
            int size = nodes.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = nodes.front();
                nodes.pop();
                level_sum += current->val;

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }
        }

        return level_sum;
    }
};