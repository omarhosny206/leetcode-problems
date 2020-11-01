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
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return sortedListToBSTRecursive(head);
    }

    TreeNode *sortedListToBSTRecursive(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *middle = getMiddle(head);
        TreeNode *root = new TreeNode(middle->val);

        if (head == middle)
            return root;

        root->left = sortedListToBSTRecursive(head);
        root->right = sortedListToBSTRecursive(middle->next);

        return root;
    }

    ListNode *getMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != nullptr)
            prev->next = nullptr;

        return slow;
    }
};