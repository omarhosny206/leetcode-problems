// https://leetcode.com/problems/determine-if-two-events-have-conflict/

class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        int firstStart = getValue(event1[0]);
        int firstEnd = getValue(event1[1]);
        int secondStart = getValue(event2[0]);
        int secondEnd = getValue(event2[1]);

        if (secondStart >= firstStart && secondStart <= firstEnd)
            return true;

        if (firstStart >= secondStart && firstStart <= secondEnd)
            return true;

        return false;
    }

    int getValue(string &time)
    {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3));

        return hours * 60 + minutes;
    }
};