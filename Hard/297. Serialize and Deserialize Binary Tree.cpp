// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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
public:
    string serialize(TreeNode *root)
    {
        string data = "";
        data = Encode(root, data);
        return data;
    }

    TreeNode *deserialize(string data)
    {
        TreeNode *root = nullptr;
        queue<string> vals;
        string val = "";

        for (char &c : data)
        {
            if (c == '.')
            {
                vals.push(val);
                val = "";
            }

            else
                val += c;
        }

        root = buildTree(vals);
        return root;
    }

    TreeNode *buildTree(queue<string> &vals)
    {
        string val = vals.front();
        vals.pop();

        if (val == "nullptr")
            return nullptr;

        TreeNode *root = new TreeNode(stoi(val));
        root->left = buildTree(vals);
        root->right = buildTree(vals);
        return root;
    }

    string Encode(TreeNode *root, string &data)
    {
        if (root == nullptr)
            return "nullptr.";

        data = to_string(root->val) + '.' + Encode(root->left, data) + Encode(root->right, data);
        return data;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));