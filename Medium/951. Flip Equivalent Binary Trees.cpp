// https://leetcode.com/problems/flip-equivalent-binary-trees/

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
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        return DFS(root1, root2);
    }

    bool DFS(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;

        if (root1 == nullptr || root2 == nullptr)
            return false;

        bool haveSameValues = (root1->val == root2->val);
        bool areEqual = DFS(root1->left, root2->left) && DFS(root1->right, root2->right);
        bool areFlipped = DFS(root1->left, root2->right) && DFS(root1->right, root2->left);

        return haveSameValues && (areEqual || areFlipped);
    }
};