// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> result;
        stack<int> firstNodes;
        stack<int> secondNodes;

        insertNodes(root1, firstNodes);
        insertNodes(root2, secondNodes);

        result = merge(firstNodes, secondNodes);

        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> merge(stack<int> &firstNodes, stack<int> &secondNodes)
    {
        vector<int> result;

        while (!firstNodes.empty() && !secondNodes.empty())
        {
            if (firstNodes.top() >= secondNodes.top())
            {
                result.push_back(firstNodes.top());
                firstNodes.pop();
            }

            else
            {
                result.push_back(secondNodes.top());
                secondNodes.pop();
            }
        }

        while (!firstNodes.empty())
        {
            result.push_back(firstNodes.top());
            firstNodes.pop();
        }

        while (!secondNodes.empty())
        {
            result.push_back(secondNodes.top());
            secondNodes.pop();
        }

        return result;
    }

    void insertNodes(TreeNode *root, stack<int> &nodes)
    {
        if (root == nullptr)
            return;

        insertNodes(root->left, nodes);
        nodes.push(root->val);
        insertNodes(root->right, nodes);
    }
};