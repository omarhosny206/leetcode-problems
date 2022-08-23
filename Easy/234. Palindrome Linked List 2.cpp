// https://leetcode.com/problems/palindrome-linked-list/

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
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        string nums = toString(head);
        return isPalindrome(nums);
    }

    bool isPalindrome(string &nums)
    {
        int i = 0;
        int j = nums.length() - 1;

        while (i < j)
        {
            if (nums[i] != nums[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    string toString(ListNode *head)
    {
        string result = "";

        while (head != nullptr)
        {
            result += to_string(head->val);
            head = head->next;
        }

        return result;
    }
};