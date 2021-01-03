// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        return BFS(original, cloned, target);
    }

    TreeNode *BFS(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr)
            return nullptr;

        queue<TreeNode *> original_queue;
        queue<TreeNode *> cloned_queue;

        original_queue.push(original);
        cloned_queue.push(cloned);

        while (!original_queue.empty())
        {
            int size = original_queue.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *original_node = original_queue.front();
                TreeNode *cloned_node = cloned_queue.front();
                original_queue.pop();
                cloned_queue.pop();

                if (original_node == target)
                    return cloned_node;

                if (original_node->left != nullptr)
                {
                    original_queue.push(original_node->left);
                    cloned_queue.push(cloned_node->left);
                }

                if (original_node->right != nullptr)
                {
                    original_queue.push(original_node->right);
                    cloned_queue.push(cloned_node->right);
                }
            }
        }

        return nullptr;
    }
};