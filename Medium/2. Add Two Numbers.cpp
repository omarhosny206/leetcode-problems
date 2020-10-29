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
        int sum = 0;
        int carry = 0;
        list<int> final_result;

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
            final_result.push_back(sum % 10);
        }

        if (carry != 0)
            final_result.push_back(carry);

        ListNode *current = new ListNode();
        ListNode *answer = current;
        while (!final_result.empty())
        {
            current->next = new ListNode(final_result.front());
            current = current->next;
            final_result.pop_front();
        }

        return answer->next;
    }
};