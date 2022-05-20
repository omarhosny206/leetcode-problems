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
        return bfs(original, cloned, target);
    }

    TreeNode *bfs(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr)
            return nullptr;

        queue<TreeNode *> originalNodes;
        queue<TreeNode *> clonedNodes;

        originalNodes.push(original);
        clonedNodes.push(cloned);

        while (!originalNodes.empty())
        {
            int size = originalNodes.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode *originalNode = originalNodes.front();
                TreeNode *clonedNode = clonedNodes.front();
                originalNodes.pop();
                clonedNodes.pop();

                if (originalNode == target)
                    return clonedNode;

                if (originalNode->left != nullptr)
                {
                    originalNodes.push(originalNode->left);
                    clonedNodes.push(clonedNode->left);
                }

                if (originalNode->right != nullptr)
                {
                    originalNodes.push(originalNode->right);
                    clonedNodes.push(clonedNode->right);
                }
            }
        }

        return nullptr;
    }
};