// https://leetcode.com/problems/watering-plants-ii/

class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int result = 0;

        int alicePointer = 0;
        int aliceCapacity = capacityA;

        int bobPointer = plants.size() - 1;
        int bobCapacity = capacityB;

        while (alicePointer < bobPointer)
        {
            if (aliceCapacity < plants[alicePointer])
            {
                aliceCapacity = capacityA;
                result++;
            }

            aliceCapacity -= plants[alicePointer++];

            if (bobCapacity < plants[bobPointer])
            {
                bobCapacity = capacityB;
                result++;
            }

            bobCapacity -= plants[bobPointer--];
        }

        if (plants.size() % 2 == 1)
        {
            int maxCapacity = max(aliceCapacity, bobCapacity);

            if (maxCapacity < plants[plants.size() / 2])
                result++;
        }

        return result;
    }
};