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
    unordered_map<int, Node *> visited;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        return dfs(node);
    }

    Node *dfs(Node *node)
    {
        if (visited[node->val] != nullptr)
            return visited[node->val];

        Node *result = new Node(node->val);
        visited[node->val] = result;

        for (Node *neighbor : node->neighbors)
            result->neighbors.push_back(dfs(neighbor));

        return result;
    }
};