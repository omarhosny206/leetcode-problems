// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem
{
    unordered_map<string, pair<double, int>> average;
    unordered_map<int, pair<string, int>> info;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        info[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        string destination = info[id].first + " --> " + stationName;
        double interval = t - info[id].second;
        average[destination].first += interval;
        average[destination].second++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string destination = startStation + " --> " + endStation;
        return average[destination].first / average[destination].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */