// https://leetcode.com/problems/complete-binary-tree-inserter/

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
class CBTInserter
{
    TreeNode *root;

public:
    CBTInserter(TreeNode *root)
    {
        this->root = root;
    }

    int insert(int v)
    {
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                if (current->left == nullptr)
                {
                    current->left = new TreeNode(v);
                    return current->val;
                }

                else
                    nodes.push(current->left);

                if (current->right == nullptr)
                {
                    current->right = new TreeNode(v);
                    return current->val;
                }

                else
                    nodes.push(current->right);
            }
        }

        return -1;
    }

    TreeNode *get_root()
    {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */