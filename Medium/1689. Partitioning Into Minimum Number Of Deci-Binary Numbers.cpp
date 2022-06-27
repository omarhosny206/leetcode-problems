
class Solution
{
public:
    int minPartitions(string n)
    {
        int result = INT_MIN;

        for (char &c : n)
            result = max(result, c - '0');

        return result;
    }
};