// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> vals;

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        insertNodes(head);
        return sortedListToBSTRecursive(0, vals.size() - 1);
    }

    TreeNode *sortedListToBSTRecursive(int left, int right)
    {
        if (left > right)
            return nullptr;

        int middle = (left + right) / 2;

        TreeNode *root = new TreeNode(vals[middle]);

        if (left == right)
            return root;

        root->left = sortedListToBSTRecursive(left, middle - 1);
        root->right = sortedListToBSTRecursive(middle + 1, right);

        return root;
    }

    void insertNodes(ListNode *head)
    {
        while (head != nullptr)
        {
            vals.push_back(head->val);
            head = head->next;
        }
    }
};