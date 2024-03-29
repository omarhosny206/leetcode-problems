// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem
{
    unordered_map<string, pair<int, int>> tripInfo;
    unordered_map<int, pair<string, int>> customerInfo;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        customerInfo[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        string startStation = customerInfo[id].first;
        string combinedStation = startStation + ":" + stationName;
        int takenTime = t - customerInfo[id].second;

        tripInfo[combinedStation].first += takenTime;
        tripInfo[combinedStation].second++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string combinedStation = startStation + ":" + endStation;
        return (double)tripInfo[combinedStation].first / tripInfo[combinedStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */