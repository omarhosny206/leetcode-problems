// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode *root)
    {
        int level = 1;
        int currentLevel = 1;
        int maxSum = INT_MIN;
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int sum = 0;
            int size = nodes.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();
                sum += current->val;

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }

            if (maxSum < sum)
            {
                maxSum = sum;
                level = currentLevel;
            }

            currentLevel++;
        }

        return level;
    }
};