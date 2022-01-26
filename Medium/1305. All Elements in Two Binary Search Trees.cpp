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
        vector<int> firstNodes;
        vector<int> secondNodes;

        insertNodes(root1, firstNodes);
        insertNodes(root2, secondNodes);

        return merge(firstNodes, secondNodes);
    }

    vector<int> merge(vector<int> &firstNodes, vector<int> &secondNodes)
    {
        vector<int> result;
        int i = 0;
        int j = 0;

        while (i < firstNodes.size() && j < secondNodes.size())
        {
            if (firstNodes[i] <= secondNodes[j])
                result.push_back(firstNodes[i++]);

            else
                result.push_back(secondNodes[j++]);
        }

        while (i < firstNodes.size())
            result.push_back(firstNodes[i++]);

        while (j < secondNodes.size())
            result.push_back(secondNodes[j++]);

        return result;
    }

    void insertNodes(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;

        insertNodes(root->left, nodes);
        nodes.push_back(root->val);
        insertNodes(root->right, nodes);
    }
};