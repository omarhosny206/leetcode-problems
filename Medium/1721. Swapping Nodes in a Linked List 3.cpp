
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
    ListNode *leftNode;
    ListNode *rightNode;

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        leftNode = head;
        rightNode = head;
        int position = k;

        getNodes(head, k, position);

        int temp = leftNode->val;
        leftNode->val = rightNode->val;
        rightNode->val = temp;

        return head;
    }

    void getNodes(ListNode *head, int &left, int &right)
    {
        if (head == nullptr)
            return;

        if (--left == 0)
            leftNode = head;

        getNodes(head->next, left, right);

        if (--right == 0)
            rightNode = head;
    }
};