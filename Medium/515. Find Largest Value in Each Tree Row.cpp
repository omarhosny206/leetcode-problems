// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        return BFS(root);
    }

    vector<int> BFS(TreeNode *root)
    {
        vector<int> result;
        queue<TreeNode *> nodes;
        nodes.push(root);
        result.push_back(root->val);

        while (!nodes.empty())
        {
            int size = nodes.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }

            queue<TreeNode *> temp = nodes;
            int maxValue = INT_MIN;
            while (!temp.empty())
            {
                maxValue = max(maxValue, temp.front()->val);
                temp.pop();
            }

            if (!nodes.empty())
                result.push_back(maxValue);
        }

        return result;
    }
};