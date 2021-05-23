// https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers
{
    vector<int> nums;

public:
    ProductOfNumbers()
    {
        nums.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            nums.erase(nums.begin(), nums.end());
            nums.push_back(1);
        }

        else
            nums.push_back(num * nums.back());
    }

    int getProduct(int k)
    {
        if (k >= nums.size())
            return 0;

        return nums.back() / nums[nums.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */