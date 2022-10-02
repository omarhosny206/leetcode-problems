// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

class Solution
{
public:
    bool equalFrequency(string word)
    {
        unordered_map<int, int> freq;

        for (char &c : word)
            freq[c - 'a']++;

        int maxValue = INT_MIN;
        int minValue = INT_MAX;

        for (auto &pair : freq)
        {
            if (pair.second > maxValue)
                maxValue = pair.second;

            if (pair.second < minValue)
                minValue = pair.second;
        }

        if (maxValue > minValue + 1)
            return false;

        for (auto &pair : freq)
            if (pair.second != maxValue && pair.second != minValue)
                return false;

        if (maxValue == minValue && minValue == 1)
            return true;

        int maxValueCounter = 0;
        int minValueCounter = 0;

        for (auto &pair : freq)
        {
            if (pair.second == maxValue)
                maxValueCounter++;

            if (pair.second == minValue)
                minValueCounter++;
        }

        if (minValueCounter > maxValueCounter)
            return maxValueCounter == 1;

        return minValueCounter == 1;
    }
};