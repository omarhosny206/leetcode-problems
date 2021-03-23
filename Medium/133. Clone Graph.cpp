// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
    map<int, Node *> visited;

public:
    Node *cloneGraph(Node *node)
    {
        return DFS(node);
    }

    Node *DFS(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        if (visited[node->val])
            return visited[node->val];

        Node *newCloneNode = new Node(node->val);
        visited[node->val] = newCloneNode;

        for (Node *n : node->neighbors)
            newCloneNode->neighbors.push_back(DFS(n));

        return newCloneNode;
    }
};