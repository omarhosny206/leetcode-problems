// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> level_order_vals;
        queue<TreeNode *> node_queue;

        if (root == nullptr)
            return level_order_vals;

        node_queue.push(root);

        while (!node_queue.empty())
        {

            int size = node_queue.size();
            vector<int> nodes(size);

            for (int i = 0; i < size; i++)
            {

                TreeNode *temp = node_queue.front();
                nodes[i] = temp->val;
                node_queue.pop();

                if (temp->left != nullptr)
                    node_queue.push(temp->left);
                if (temp->right != nullptr)
                    node_queue.push(temp->right);
            }
            level_order_vals.push_back(nodes);
        }

        return level_order_vals;
    }
};