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
        map<Node *, Node *> nodes;
        return linkedListBuilder(head, nodes);
    }

    Node *linkedListBuilder(Node *head, map<Node *, Node *> &nodes)
    {
        if (!head)
            return nullptr;

        if (nodes.find(head) != nodes.end())
            return nodes[head];

        Node *current = new Node(head->val);
        nodes[head] = current;
        current->next = linkedListBuilder(head->next, nodes);
        current->random = linkedListBuilder(head->random, nodes);
        return current;
    }
};