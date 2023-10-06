// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

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
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        return bfs(root);
    }

    Node *bfs(Node *root)
    {
        queue<Node *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();
            Node *right = nullptr;

            for (int i = 0; i < size; ++i)
            {
                Node *current = nodes.front();
                nodes.pop();

                current->next = right;
                right = current;

                if (current->right)
                    nodes.push(current->right);

                if (current->left)
                    nodes.push(current->left);
            }
        }

        return root;
    }
};