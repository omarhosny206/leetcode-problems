// https://leetcode.com/problems/find-all-the-lonely-nodes/

class Solution
{
    vector<int> result;

public:
    vector<int> getLonelyNodes(TreeNode *root)
    {
        DFS(root);
        return result;
    }

    void DFS(TreeNode *root)
    {
        if (!root)
            return;

        if (root->left == nullptr && root->right != nullptr)
            result.push_back(root->right->val);

        else if (root->right == nullptr && root->left != nullptr)
            result.push_back(root->left->val);

        DFS(root->left);
        DFS(root->right);
    }
};