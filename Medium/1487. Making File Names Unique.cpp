// https://leetcode.com/problems/making-file-names-unique/

class Solution
{
public:
    vector<string> getFolderNames(vector<string> &names)
    {
        vector<string> answer;
        unordered_map<string, int> reservedNames;
        for (string name : names)
        {
            if (reservedNames[name] == 0)
            {
                reservedNames[name]++;
                answer.push_back(name);
            }
            else
            {
                int i = reservedNames[name]++;
                while (reservedNames[name + "(" + to_string(i) + ")"] > 0)
                    i++;

                string result = name + "(" + to_string(i) + ")";
                reservedNames[result]++;
                answer.push_back(result);
            }
        }

        return answer;
    }
};