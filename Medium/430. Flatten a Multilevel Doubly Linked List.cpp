// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
    vector<Node *> nodes;

public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return head;

        Node *result = head;
        DFS(head);

        for (int i = 0; i < nodes.size(); ++i)
        {
            head->prev = (i == 0) ? nullptr : nodes[i - 1];
            head->next = (i == nodes.size() - 1) ? nullptr : nodes[i + 1];
            head->child = nullptr;
            head = head->next;
        }

        return result;
    }

    void DFS(Node *head)
    {
        if (head == nullptr)
            return;
        nodes.push_back(head);
        DFS(head->child);
        DFS(head->next);
    }
};