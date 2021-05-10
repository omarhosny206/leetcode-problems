// https://leetcode.com/problems/seat-reservation-manager/

class SeatManager
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    SeatManager(int n)
    {
        for (int i = n; i >= 1; --i)
            minHeap.push(i);
    }

    int reserve()
    {
        int seat = minHeap.top();
        minHeap.pop();

        return seat;
    }

    void unreserve(int seatNumber)
    {
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */