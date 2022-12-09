// https://leetcode.com/problems/restore-ip-addresses/

class Solution
{
    vector<string> result;
    vector<string> current;

public:
    vector<string> restoreIpAddresses(string s)
    {
        current = vector<string>(4);

        dfs(s, 0, 0);
        return result;
    }

    void dfs(string &s, int index, int counter)
    {
        if (counter == current.size() - 1)
        {
            string value = s.substr(index);

            if (checkSingleValue(value) == true)
            {
                current[counter] = value;

                string ipAddresse = toIpAddresse(current);
                result.push_back(ipAddresse);
            }

            return;
        }

        for (int i = index; i < s.length(); ++i)
        {
            string value = s.substr(index, i + 1 - index);

            if (checkSingleValue(value) == false)
                break;

            current[counter] = value;
            dfs(s, i + 1, counter + 1);
        }
    }

    bool checkSingleValue(string &value)
    {
        if (value.length() == 0 || value.length() > 3)
            return false;

        if (value[0] == '0' && value.length() > 1)
            return false;

        int number = stoi(value);
        return number <= 255;
    }

    string toIpAddresse(vector<string> &values)
    {
        string result = "";

        for (string &value : values)
            result += value + ".";

        result.pop_back();
        return result;
    }
};