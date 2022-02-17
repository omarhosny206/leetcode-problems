// https://leetcode.com/problems/open-the-lock/

class Solution
{
    queue<string> nodes;
    unordered_set<string> blockedLocks;
    unordered_set<string> visited;

public:
    int openLock(vector<string> &deadends, string target)
    {
        int numTurns = 0;
        string start = "0000";
        vector<int> moves = {1, -1};

        if (start == target)
            return 0;

        for (string &deadend : deadends)
            blockedLocks.insert(deadend);

        if (blockedLocks.find(start) != blockedLocks.end())
            return -1;

        nodes.push(start);
        visited.insert(start);

        while (!nodes.empty())
        {
            numTurns++;
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                string current = nodes.front();
                nodes.pop();

                for (int j = 0; j < current.length(); ++j)
                {
                    string temp = current;

                    for (int k = 0; k < moves.size(); ++k)
                    {
                        temp[j] = (((current[j] - '0') + moves[k] + 10) % 10) + '0';

                        if (temp == target)
                            return numTurns;

                        if (isOk(temp))
                        {
                            nodes.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
        }

        return -1;
    }

    bool isOk(string &lock)
    {
        return (blockedLocks.find(lock) == blockedLocks.end()) && (visited.find(lock) == visited.end());
    }
};