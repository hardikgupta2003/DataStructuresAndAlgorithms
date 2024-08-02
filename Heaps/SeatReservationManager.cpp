#include "bits/stdc++.h"
using namespace std;

class SeatManager
{
    priority_queue<int, vector<int>, greater<int>> unReserved;

public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            unReserved.push(i);
        }
    }

    int reserve()
    {
        int seat = unReserved.top();
        unReserved.pop();
        return seat;
    }

    void unreserve(int seatNumber) { unReserved.push(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */