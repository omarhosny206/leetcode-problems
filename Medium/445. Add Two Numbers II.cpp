// https://leetcode.com/problems/add-two-numbers-ii/

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
        stack<int> vals1;
        stack<int> vals2;

        while (l1 != nullptr)
        {
            vals1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            vals2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = new ListNode();
        int sum = 0, carry = 0;

        while (!vals1.empty() || !vals2.empty())
        {

            sum = carry;

            if (!vals1.empty())
            {
                sum += vals1.top();
                vals1.pop();
            }

            if (!vals2.empty())
            {
                sum += vals2.top();
                vals2.pop();
            }

            head->val = sum % 10;
            carry = sum / 10;
            ListNode *current = new ListNode(carry);
            current->next = head;
            head = current;
        }

        return head->val == 0 ? head->next : head;
    }
};