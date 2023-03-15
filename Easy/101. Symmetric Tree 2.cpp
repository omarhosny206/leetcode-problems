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
        queue<TreeNode *> nodes;

        nodes.push(root->left);
        nodes.push(root->right);

        while (!nodes.empty())
        {
            TreeNode *firstNode = nodes.front();
            nodes.pop();

            TreeNode *secondNode = nodes.front();
            nodes.pop();

            if (firstNode == nullptr && secondNode != nullptr)
                return false;

            if (firstNode != nullptr && secondNode == nullptr)
                return false;

            if (firstNode != nullptr && secondNode != nullptr)
            {
                if (firstNode->val != secondNode->val)
                    return false;

                nodes.push(firstNode->left);
                nodes.push(secondNode->right);
                nodes.push(firstNode->right);
                nodes.push(secondNode->left);
            }
        }

        return true;
    }
};