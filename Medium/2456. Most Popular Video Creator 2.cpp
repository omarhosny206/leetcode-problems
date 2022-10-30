// https://leetcode.com/problems/most-popular-video-creator/submissions/

class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        vector<vector<string>> result;
        unordered_map<string, long long> viewsValue;
        unordered_map<string, pair<string, long long>> creatorInfo;
        long long maxViewsValue = LLONG_MIN;

        for (int i = 0; i < creators.size(); ++i)
        {
            if (viewsValue.find(creators[i]) == viewsValue.end())
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

            viewsValue[creators[i]] += views[i];
            maxViewsValue = max(maxViewsValue, viewsValue[creators[i]]);
        }

        for (int i = 0; i < creators.size(); ++i)
        {
            if (viewsValue[creators[i]] == maxViewsValue)
            {
                result.push_back({creators[i], creatorInfo[creators[i]].first});
                viewsValue[creators[i]] = 0;
            }
        }

        return result;
    }
};