// https://leetcode.com/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
    TreeNode *root;

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string data = "";
        Encode(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        TreeNode *root = nullptr;
        int val = 0;

        for (char &c : data)
        {
            if (c == '.')
            {
                root = Insert(root, val);
                val = 0;
            }

            else
                val = val * 10 + (c - '0');
        }

        return root;
    }

    TreeNode *Insert(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);

        if (root->val > val)
            root->left = Insert(root->left, val);

        else
            root->right = Insert(root->right, val);

        return root;
    }

    void Encode(TreeNode *root, string &data)
    {
        if (root == nullptr)
            return;

        data += to_string(root->val) + ".";
        Encode(root->left, data);
        Encode(root->right, data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;