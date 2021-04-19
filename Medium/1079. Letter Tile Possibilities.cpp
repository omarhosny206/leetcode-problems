// https://leetcode.com/problems/letter-tile-possibilities/

class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        vector<int> freq(26);

        for (char c : tiles)
            freq[c - 'A']++;

        return DFS(tiles, freq);
    }

    int DFS(string &tiles, vector<int> &freq)
    {
        int counter = 0;

        for (int i = 0; i < 26; ++i)
        {
            if (freq[i] != 0)
            {
                counter++;
                freq[i]--;
                counter += DFS(tiles, freq);
                freq[i]++;
            }
        }

        return counter;
    }
};