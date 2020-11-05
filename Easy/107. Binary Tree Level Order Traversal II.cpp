// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        queue<TreeNode *> nodes;
        vector<vector<int>> result;

        nodes.push(root);

        while (!nodes.empty())
        {
            vector<int> temp;
            int size = nodes.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = nodes.front();
                temp.push_back(current->val);
                nodes.pop();

                if (current->left)
                    nodes.push(current->left);
                if (current->right)
                    nodes.push(current->right);
            }
            result.push_back(temp);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};