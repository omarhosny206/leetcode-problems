class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int result = 0;
        priority_queue<int, vector<int>, greater<int>> values;

        for (int &cost : costs)
            values.push(cost);

        while (!values.empty())
        {
            int value = values.top();
            values.pop();

            if (coins < value)
                break;

            coins -= value;
            result++;
        }

        return result;
    }
};