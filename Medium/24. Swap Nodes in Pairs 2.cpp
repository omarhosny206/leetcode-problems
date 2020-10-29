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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr)
            return head;
        
        queue<ListNode*> even;
        queue<ListNode*> odd;
        ListNode* current = head;
        int i = 0;
        while(current != nullptr) {
            (i == 0 || i % 2 == 0) ? odd.push(current) : even.push(current);
            current = current->next;
            i++;
        }
        
        ListNode* result = new ListNode();
        current = result;
        
        
        while (!even.empty() || !odd.empty()) {
            
            if(!even.empty()) {
                current->next = new ListNode(even.front()->val);
                current = current->next;
                even.pop();
            }
            
            if(!odd.empty()) {
                current->next = new ListNode(odd.front()->val);
                current = current->next;
                odd.pop();
            }
        }
        
        
        return result->next;
    }
};