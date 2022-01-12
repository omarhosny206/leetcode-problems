// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);

        insert(root, val);
        return root;
    }

    void insert(TreeNode *root, int val)
    {
        while (root != nullptr)
        {
            if (root->val > val)
            {
                if (root->left == nullptr)
                {
                    root->left = new TreeNode(val);
                    return;
                }
                root = root->left;
            }

            else
            {
                if (root->right == nullptr)
                {
                    root->right = new TreeNode(val);
                    return;
                }
                root = root->right;
            }
        }
    }
};