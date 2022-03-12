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
    unordered_map<Node *, Node *> nodes;

public:
    Node *copyRandomList(Node *head)
    {
        return deepCopy(head);
    }

    Node *deepCopy(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        if (nodes[head] != nullptr)
            return nodes[head];

        Node *current = new Node(head->val);
        nodes[head] = current;

        current->next = deepCopy(head->next);
        current->random = deepCopy(head->random);

        return current;
    }
};