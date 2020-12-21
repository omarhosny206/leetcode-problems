// https://leetcode.com/problems/shuffle-an-array/

class Solution
{
    vector<int> array, original;
    default_random_engine seed;

public:
    Solution(const vector<int> &nums) : original(nums), array(nums), seed(random_device{}()) {}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        array = original;
        return array;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int i = array.size() - 1; i > 0; --i)
        {
            auto index = uniform_int_distribution<int>(0, i)(seed);
            swap(array[i], array[index]);
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */