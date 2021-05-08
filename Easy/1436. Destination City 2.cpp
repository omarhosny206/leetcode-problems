// https://leetcode.com/problems/destination-city/

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        string city = paths[0][0];
        unordered_map<string, string> destination;

        for (int i = 0; i < paths.size(); ++i)
            destination[paths[i][0]] = paths[i][1];

        while (destination.find(city) != destination.end())
            city = destination[city];

        return city;
    }
};