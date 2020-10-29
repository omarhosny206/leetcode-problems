// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
        vector<int> nodes;
        insertNodes(root1, nodes);
        insertNodes(root2, nodes);
        quicksort(nodes, 0, nodes.size() - 1);
        return nodes;
    }

    void insertNodes(TreeNode *root, vector<int> &nodes)
    {
        if (root == nullptr)
            return;
        nodes.push_back(root->val);
        insertNodes(root->left, nodes);
        insertNodes(root->right, nodes);
    }

    int partition(vector<int> &nodes, int left, int right)
    {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = nodes[pivotIndex];
        int i = left, j = right;
        int temp;
        while (i <= j)
        {
            while (nodes[i] < pivotValue)
            {
                i++;
            }
            while (nodes[j] > pivotValue)
            {
                j--;
            }
            if (i <= j)
            {
                temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }

    void quicksort(vector<int> &nodes, int left, int right)
    {
        if (left < right)
        {
            int pivotIndex = partition(nodes, left, right);
            quicksort(nodes, left, pivotIndex - 1);
            quicksort(nodes, pivotIndex, right);
        }
    }
};