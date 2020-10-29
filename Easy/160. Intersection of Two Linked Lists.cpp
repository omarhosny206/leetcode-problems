// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> nodes;
        while (headA != nullptr)
        {
            nodes.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr)
        {
            if (nodes.find(headB) != nodes.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};