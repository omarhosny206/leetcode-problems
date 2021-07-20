// https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode *> result;

public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int size = getSize(head);
        insertParts(head, size, k);
        return result;
    }

    void insertParts(ListNode *head, int size, int k)
    {
        ListNode *current = head;
        int nodes = size / k;
        int extraNodes = size % k;

        while (current != nullptr)
        {
            result.push_back(current);

            int counter = 1;
            while (counter < nodes)
            {
                counter++;
                current = current->next;
            }

            if (extraNodes > 0 && size > k)
            {
                extraNodes--;
                current = current->next;
            }

            ListNode *temp = current->next;
            current->next = nullptr;
            current = temp;
        }

        while (size < k)
        {
            result.push_back(nullptr);
            size++;
        }
    }

    int getSize(ListNode *head)
    {
        int size = 0;
        ListNode *current = head;

        while (current != nullptr)
        {
            size++;
            current = current->next;
        }

        return size;
    }
};