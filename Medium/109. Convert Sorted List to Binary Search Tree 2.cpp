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
        vector<int> values = getValues(head);
        return dfs(values, 0, values.size() - 1);
    }

    TreeNode *dfs(vector<int> &values, int left, int right)
    {
        if (left > right)
            return nullptr;

        int middle = left + (right - left) / 2;
        TreeNode *root = new TreeNode(values[middle]);

        root->left = dfs(values, left, middle - 1);
        root->right = dfs(values, middle + 1, right);
        return root;
    }

    vector<int> getValues(ListNode *head)
    {
        vector<int> result;

        while (head != nullptr)
        {
            result.push_back(head->val);
            head = head->next;
        }

        return result;
    }
};