// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> check;

        check.push(root->left);
        check.push(root->right);

        while (!check.empty())
        {
            TreeNode *node1 = check.front();
            check.pop();
            TreeNode *node2 = check.front();
            check.pop();
            if (!node1 && node2)
                return false;
            if (!node2 && node1)
                return false;
            if (node1 && node2)
            {
                if (node1->val != node2->val)
                    return false;
                check.push(node1->left);
                check.push(node2->right);
                check.push(node1->right);
                check.push(node2->left);
            }
        }

        return true;
    }
};