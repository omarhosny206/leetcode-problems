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
    ListNode *head;

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        this->head = head;
        int size = getSize(head);
        return sortedListToBSTRecursive(0, size - 1);
    }

    TreeNode *sortedListToBSTRecursive(int l, int r)
    {
        if (l > r)
            return nullptr;

        int middle = (l + r) / 2;

        TreeNode *left = sortedListToBSTRecursive(l, middle - 1);

        TreeNode *node = new TreeNode(head->val);
        node->left = left;

        head = head->next;
        node->right = sortedListToBSTRecursive(middle + 1, r);

        return node;
    }

    int getSize(ListNode *head)
    {
        ListNode *current = head;
        int count = 0;
        while (current != nullptr)
        {
            current = current->next;
            count++;
        }
        return count;
    }
};