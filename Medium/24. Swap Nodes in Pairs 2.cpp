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
        if (head == nullptr)
            return nullptr;

        ListNode *result = new ListNode();
        ListNode *current = result;

        ListNode *odd = new ListNode();
        ListNode *currentOdd = odd;

        ListNode *even = new ListNode();
        ListNode *currentEven = even;

        int i = 1;

        while (head != nullptr)
        {
            if (i % 2 == 0)
            {
                currentEven->next = head;
                currentEven = currentEven->next;
                head = head->next;
                currentEven->next = nullptr;
            }

            else
            {
                currentOdd->next = head;
                currentOdd = currentOdd->next;
                head = head->next;
                currentOdd->next = nullptr;
            }

            i++;
        }

        odd = odd->next;
        even = even->next;

        while (odd != nullptr || even != nullptr)
        {
            if (even != nullptr)
            {
                current->next = even;
                current = current->next;
                even = even->next;
            }

            if (odd != nullptr)
            {
                current->next = odd;
                current = current->next;
                odd = odd->next;
            }
        }

        return result->next;
    }
};