// https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        vector<vector<string>> result;
        map<int, unordered_map<string, int>> table;
        set<string> foods;
        int i = 1;

        for (vector<string> order : orders)
        {
            table[stoi(order[1])][order[2]]++;
            foods.insert(order[2]);
        }

        result.push_back({"Table"});
        for (string food : foods)
            result[0].push_back(food);

        for (auto pair : table)
        {
            result.push_back({to_string(pair.first)});

            for (string food : foods)
                result[i].push_back(to_string(table[pair.first][food]));

            i++;
        }

        return result;
    }
};