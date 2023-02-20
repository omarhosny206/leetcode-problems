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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        return bfs(root);
    }

    vector<vector<int>> bfs(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        queue<TreeNode *> nodes;
        bool shouldBeReversed = false;

        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();
            vector<int> values;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                if (current->left)
                    nodes.push(current->left);

                if (current->right)
                    nodes.push(current->right);

                values.push_back(current->val);
            }

            if (shouldBeReversed)
                reverse(values.begin(), values.end());

            result.push_back(values);
            shouldBeReversed = !shouldBeReversed;
        }

        return result;
    }
};