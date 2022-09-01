// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int result = 1;

public:
    int goodNodes(TreeNode *root)
    {
        bfs(root);
        return result;
    }

    void bfs(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> nodes;
        nodes.push({root, root->val});

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                pair<TreeNode *, int> current = nodes.front();
                nodes.pop();

                if (current.first->left)
                {
                    pair<TreeNode *, int> newLeftNode = {current.first->left, max(current.first->left->val, current.second)};

                    if (newLeftNode.second == newLeftNode.first->val)
                        result++;

                    nodes.push(newLeftNode);
                }

                if (current.first->right)
                {
                    pair<TreeNode *, int> newRightNode = {current.first->right, max(current.first->right->val, current.second)};

                    if (newRightNode.second == newRightNode.first->val)
                        result++;

                    nodes.push(newRightNode);
                }
            }
        }
    }
};