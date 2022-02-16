// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *result = new ListNode();
        ListNode *current = result;

        queue<int> even;
        queue<int> odd;

        int i = 1;

        while (head != nullptr)
        {
            (i % 2 == 0) ? even.push(head->val) : odd.push(head->val);
            head = head->next;
            i++;
        }

        while (!even.empty() || !odd.empty())
        {

            if (!even.empty())
            {
                current->next = new ListNode(even.front());
                even.pop();
                current = current->next;
            }

            if (!odd.empty())
            {
                current->next = new ListNode(odd.front());
                odd.pop();
                current = current->next;
            }
        }

        return result->next;
    }
};