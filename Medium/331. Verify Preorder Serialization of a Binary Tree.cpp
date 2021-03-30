// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int counter = 0;

        for (int i = 0; i < preorder.size(); ++i)
        {
            if (preorder[i] == ',')
                continue;

            if (counter < 0)
                return false;

            if (preorder[i] == '#')
                counter--;

            else
            {
                while (i < preorder.size() && preorder[i] != ',')
                    i++;

                counter++;
            }
        }

        return counter == -1;
    }
};