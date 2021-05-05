// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> result;
        stack<int> nums;

        head = Reverse(head);

        while (head != nullptr)
        {
            while (!nums.empty() && nums.top() <= head->val)
                nums.pop();

            int value = nums.empty() ? 0 : nums.top();
            result.push_back(value);

            nums.push(head->val);
            head = head->next;
        }

        Reverse(result);
        return result;
    }

    ListNode *Reverse(ListNode *head)
    {
        ListNode *current = head;
        ListNode *previous = nullptr;
        ListNode *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }

    void Reverse(vector<int> &data)
    {
        int i = 0;
        int j = data.size() - 1;

        while (i < j)
        {
            int temp = data[i];
            data[i++] = data[j];
            data[j--] = temp;
        }
    }
};