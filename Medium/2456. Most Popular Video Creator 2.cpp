// https://leetcode.com/problems/most-popular-video-creator/

class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        vector<vector<string>> result;
        unordered_map<string, long long> creatorViews;
        unordered_map<string, pair<string, long long>> creatorInfo;
        long long maxViewsValue = LLONG_MIN;

        for (int i = 0; i < creators.size(); ++i)
        {
            if (creatorViews.find(creators[i]) == creatorViews.end())
            {
                creatorInfo[creators[i]].first = ids[i];
                creatorInfo[creators[i]].second = views[i];
            }

            else if (views[i] > creatorInfo[creators[i]].second)
            {
                creatorInfo[creators[i]].first = ids[i];
                creatorInfo[creators[i]].second = views[i];
            }

            else if ((views[i] == creatorInfo[creators[i]].second) && (ids[i] < creatorInfo[creators[i]].first))
            {

                creatorInfo[creators[i]].first = ids[i];
                creatorInfo[creators[i]].second = views[i];
            }

            creatorViews[creators[i]] += views[i];
            maxViewsValue = max(maxViewsValue, creatorViews[creators[i]]);
        }

        for (int i = 0; i < creators.size(); ++i)
        {
            if (creatorViews[creators[i]] == maxViewsValue)
            {
                result.push_back({creators[i], creatorInfo[creators[i]].first});
                creatorViews[creators[i]] = 0;
            }
        }

        return result;
    }
};