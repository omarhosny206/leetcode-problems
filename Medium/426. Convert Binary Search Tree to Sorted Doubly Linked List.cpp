// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution
{
    TreeNode *tail = nullptr;

public:
    TreeNode *treeToDoublyList(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *head = new TreeNode(0);
        tail = head;
        DFS(root);

        head = head->right;
        head->left = tail;
        tail->right = head;

        return head;
    }

    void DFS(TreeNode *root)
    {
        if (root == nullptr)
            return;

        DFS(root->left);
        tail->right = root;
        root->left = tail;
        tail = root;
        DFS(root->right);
    }
};