// https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return bfs(root, low, high);
    }

    int bfs(TreeNode *root, int low, int high)
    {
        int result = 0;
        queue<TreeNode *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                if (current->val >= low && current->val <= high)
                    result += current->val;

                if (current->left != nullptr && current->val >= low)
                    nodes.push(current->left);

                if (current->right != nullptr && current->val <= high)
                    nodes.push(current->right);
            }
        }

        return result;
    }
};