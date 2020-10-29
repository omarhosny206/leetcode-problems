// https://leetcode.com/problems/count-primes/

class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0;
        bool primes[n + 1];
        memset(primes, true, sizeof(primes));

        for (int i = 2; i * i < n; i++)
        {
            if (primes[i] == true)
                for (int j = i * i; j < n; j += i)
                    primes[j] = false;
        }

        for (int i = 2; i < n; i++)
        {
            if (primes[i])
                count++;
        }

        return count;
    }
};