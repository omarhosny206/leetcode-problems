class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long result = 0;
        priority_queue<double> values;

        for (int &num : nums)
            values.push(num);

        while (k--)
        {
            double value = values.top();
            values.pop();

            result += value;
            value = ceil(value / 3);

            if (value != 0)
                values.push(value);
        }

        return result;
    }
};