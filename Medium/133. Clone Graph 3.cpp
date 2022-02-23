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
            return node;

        return bfs(node);
    }

    Node *bfs(Node *node)
    {
        Node *result = new Node(node->val);
        queue<Node *> nodes;

        nodes.push(node);
        visited[node->val] = result;

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                Node *current = nodes.front();
                nodes.pop();

                for (Node *neighbor : current->neighbors)
                {
                    if (visited[neighbor->val] != nullptr)
                        visited[current->val]->neighbors.push_back(visited[neighbor->val]);

                    else
                    {
                        visited[neighbor->val] = new Node(neighbor->val);
                        visited[current->val]->neighbors.push_back(visited[neighbor->val]);
                        nodes.push(neighbor);
                    }
                }
            }
        }

        return result;
    }
};