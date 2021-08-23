// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap
{
    unordered_map<string, vector<pair<string, int>>> valueTimePair;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        valueTimePair[key].push_back({value, timestamp});
    }

    string get(string key, int t)
    {
        string result = "";
        int i = 0;
        int j = valueTimePair[key].size() - 1;

        while (i <= j)
        {
            int middle = i + (j - i) / 2;

            if (valueTimePair[key][middle].second <= t)
            {
                result = valueTimePair[key][middle].first;
                i = middle + 1;
            }

            else
                j = middle - 1;
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */