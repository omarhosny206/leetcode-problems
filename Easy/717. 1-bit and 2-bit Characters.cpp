// https://leetcode.com/problems/1-bit-and-2-bit-characters/

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int counter = 0;

        for (int i = bits.size() - 2; i >= 0; --i)
        {
            if (bits[i] == 1)
                counter++;
            else
                break;
        }

        return counter % 2 == 0;
    }
};