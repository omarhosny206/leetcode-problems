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
        return dfs(0, size - 1);
    }

    TreeNode *dfs(int i, int j)
    {
        if (i > j)
            return nullptr;

        int middle = i + (j - i) / 2;
        TreeNode *left = dfs(i, middle - 1);

        TreeNode *root = new TreeNode(head->val);
        root->left = left;

        head = head->next;
        root->right = dfs(middle + 1, j);

        return root;
    }

    int getSize(ListNode *head)
    {
        int result = 0;
        ListNode *current = head;

        while (current != nullptr)
        {
            result++;
            current = current->next;
        }

        return result;
    }
};