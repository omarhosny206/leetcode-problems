// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        return deepCopy(head);
    }

    Node *deepCopy(Node *head)
    {
        unordered_map<Node *, Node *> nodes;
        Node *current = head;

        while (current != nullptr)
        {
            nodes[current] = new Node(current->val);
            current = current->next;
        }

        current = head;

        while (current != nullptr)
        {
            nodes[current]->next = nodes[current->next];
            nodes[current]->random = nodes[current->random];
            current = current->next;
        }

        return nodes[head];
    }
};