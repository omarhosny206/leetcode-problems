// https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return constructMaximumBinaryTreeRecursive(nums, 0, nums.size() - 1);
    }

    TreeNode *constructMaximumBinaryTreeRecursive(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        int max = nums[start];
        int index = start;
        for (int i = start + 1; i <= end; ++i)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                index = i;
            }
        }

        TreeNode *root = new TreeNode(max);
        cout << root->val << endl;
        root->left = constructMaximumBinaryTreeRecursive(nums, start, index - 1);
        root->right = constructMaximumBinaryTreeRecursive(nums, index + 1, end);

        return root;
    }
};