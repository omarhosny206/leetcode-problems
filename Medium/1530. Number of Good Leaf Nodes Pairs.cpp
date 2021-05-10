// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

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
    int result = 0;

public:
    int countPairs(TreeNode *root, int distance)
    {
        DFS(root, distance);
        return result;
    }

    vector<int> DFS(TreeNode *root, int distance)
    {
        vector<int> depth;

        if (root == nullptr)
            return {};

        if (root->left == nullptr && root->right == nullptr)
            return {1};

        vector<int> left = DFS(root->left, distance);
        vector<int> right = DFS(root->right, distance);

        for (int &leftDepth : left)
            for (int &rightDepth : right)
                if (leftDepth + rightDepth <= distance)
                    result++;

        for (int &leftDepth : right)
            if (leftDepth + 1 < distance)
                depth.push_back(leftDepth + 1);

        for (int &rightDepth : left)
            if (rightDepth + 1 < distance)
                depth.push_back(rightDepth + 1);

        return depth;
    }
};