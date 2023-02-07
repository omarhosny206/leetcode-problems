
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int result = 0;
        unordered_map<int, int> freq;
        int i = 0;
        int j = 0;
        int counter = 0;

        while (j < fruits.size())
        {
            if (++freq[fruits[j]] == 1)
                counter++;

            while (counter > 2)
            {
                if (--freq[fruits[i]] == 0)
                    counter--;

                i++;
            }

            int windowSize = j - i + 1;
            result = max(result, windowSize);
            j++;
        }

        return result;
    }
};