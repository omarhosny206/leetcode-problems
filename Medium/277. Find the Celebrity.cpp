// https://leetcode.com/problems/find-the-celebrity/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution
{
public:
    int findCelebrity(int n)
    {
        int celebrity = 0;

        for (int i = 1; i < n; ++i)
            if (knows(celebrity, i) == true)
                celebrity = i;

        return isCelebrity(celebrity, n) == true ? celebrity : -1;
    }

    bool isCelebrity(int celebrity, int n)
    {
        for (int i = 0; i < n; ++i)
            if (i != celebrity && (knows(i, celebrity) == false || knows(celebrity, i) == true))
                return false;

        return true;
    }
};