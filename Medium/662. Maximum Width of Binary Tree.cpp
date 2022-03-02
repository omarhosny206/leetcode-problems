// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode *root)
    {
        int result = 1;
        queue<pair<TreeNode *, int>> nodes;

        nodes.push({root, 0});

        while (!nodes.empty())
        {
            int size = nodes.size();
            int start = nodes.front().second;
            int end = nodes.back().second;

            result = max(result, end - start + 1);

            for (int k = 0; k < size; ++k)
            {
                TreeNode *current = nodes.front().first;
                int position = nodes.front().second - start;
                nodes.pop();

                if (current->left != nullptr)
                    nodes.push({current->left, (long long)position * 2 + 1});

                if (current->right != nullptr)
                    nodes.push({current->right, (long long)position * 2 + 2});
            }
        }

        return result;
    }
};