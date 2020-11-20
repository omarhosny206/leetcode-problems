// https://leetcode.com/problems/distribute-candies-to-people/

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int totalGivenCandies = 0;
        int givenCandies = 1;
        int i = 0;
        vector<int> peopleCandies(num_people);

        while (totalGivenCandies < candies)
        {
            if (givenCandies + totalGivenCandies > candies)
            {
                peopleCandies[i] += abs(totalGivenCandies - candies);
                break;
            }

            peopleCandies[i] += givenCandies;
            i++;
            i %= num_people;
            totalGivenCandies += givenCandies;
            givenCandies++;
        }

        return peopleCandies;
    }
};