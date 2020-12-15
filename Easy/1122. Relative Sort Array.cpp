// https://leetcode.com/problems/relative-sort-array/

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> freq;
        map<int, int> visited;
        vector<int> answer;

        int n = arr1.size();
        for (int num : arr1)
        {
            freq[num]++;
            visited[num] = 0;
        }

        for (int num : arr2)
        {
            visited[num] = 1;
            int counter = freq[num];

            while (counter--)
                answer.push_back(num);
        }

        for (auto pair : visited)
        {
            if (pair.second == 0)
            {
                int counter = freq[pair.first];
                while (counter--)
                    answer.push_back(pair.first);
            }
        }

        return answer;
    }
};