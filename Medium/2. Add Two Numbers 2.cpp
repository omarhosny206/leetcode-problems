// https://leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        ListNode *current = result;

        vector<int> values;

        int sum = 0;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            sum = carry;

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            values.push_back(sum % 10);
        }

        if (carry != 0)
            values.push_back(carry);

        for (int &value : values)
        {
            current->next = new ListNode(value);
            current = current->next;
        }

        return result->next;
    }
};