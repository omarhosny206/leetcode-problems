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
    vector<int> result;

public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return result;

        bfs(root);
        return result;
    }

    void bfs(TreeNode *root)
    {
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

            if (nodes.size() > 0)
                result.push_back(nodes.back()->val);
        }
    }
};