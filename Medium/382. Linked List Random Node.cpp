// https://leetcode.com/problems/linked-list-random-node/

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
    ListNode *head = nullptr;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *h)
    {
        head = h;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        ListNode *current = head;
        ListNode *result;
        int n = 1;
        while (current != nullptr)
        {
            if (rand() % n == 0)
                result = current;

            current = current->next;
            n++;
        }

        return result->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */