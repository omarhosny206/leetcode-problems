// https://leetcode.com/problems/find-k-closest-elements/

class Solution
{
private:
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> values;

        for (int i = 0; i < arr.size(); i++)
            values.push({abs(arr[i] - x), arr[i]});

        while (k--)
        {
            result.push_back(values.top().second);
            values.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};