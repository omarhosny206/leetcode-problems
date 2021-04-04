// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements
{
    unordered_map<int, bool> nodes;

public:
    FindElements(TreeNode *root)
    {
        DFS(root, 0);
    }

    bool find(int target)
    {
        return nodes[target];
    }

    void DFS(TreeNode *root, int newVal)
    {
        if (root == nullptr)
            return;

        root->val = newVal;
        nodes[root->val] = true;
        DFS(root->left, (newVal * 2) + 1);
        DFS(root->right, (newVal * 2) + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */