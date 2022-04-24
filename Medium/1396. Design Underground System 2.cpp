// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem
{
    unordered_map<int, string> place;
    unordered_map<string, int> time;
    unordered_map<string, pair<int, int>> tripInfo;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        place[id] = stationName;
        string customerStation = to_string(id) + ":" + stationName;
        time[customerStation] = t;
    }

    void checkOut(int id, string stationName, int t)
    {
        string startStation = place[id];
        string combinedStation = startStation + ":" + stationName;

        string customerStation = to_string(id) + ":" + startStation;

        int takenTime = t - time[customerStation];

        tripInfo[combinedStation].first += takenTime;
        tripInfo[combinedStation].second++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string combinedStation = startStation + ":" + endStation;
        return (double)tripInfo[combinedStation].first / (double)tripInfo[combinedStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */