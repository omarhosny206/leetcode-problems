// https://leetcode.com/problems/rotate-string/

class Solution
{
public:
    bool rotateString(string A, string B)
    {

        if (A.size() != B.size())
            return false;

        if (A == B)
            return true;

        int length = B.size();
        while (length--)
        {
            if (A == B)
                return true;

            A = A.substr(1) + A[0];
        }
        return false;
    }
};