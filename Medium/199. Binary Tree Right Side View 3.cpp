// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<int> result;
        queue<TreeNode *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();
            TreeNode *current;

            for (int i = 0; i < size; ++i)
            {
                current = nodes.front();
                nodes.pop();

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }

            result.push_back(current->val);
        }

        return result;
    }
};