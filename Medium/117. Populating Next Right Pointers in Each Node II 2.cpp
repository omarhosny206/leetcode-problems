// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
    unordered_map<int, vector<Node *>> nodes;

public:
    Node *connect(Node *root)
    {
        dfs(root, 0);

        for (auto &level : nodes)
            for (int i = 0; i < level.second.size() - 1; ++i)
                level.second[i]->next = level.second[i + 1];

        return root;
    }

    void dfs(Node *root, int level)
    {
        if (root == nullptr)
            return;

        nodes[level].push_back(root);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};