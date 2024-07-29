#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, float>> cars; // pair of position and time to reach target

        // Calculate the time each car takes to reach the target
        for (int i = 0; i < position.size(); i++)
        {
            float time = (float)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort the cars based on their starting position in increasing order
        sort(cars.begin(), cars.end());

        stack<float> st;

        // Iterate through the sorted cars from the closest to the farthest
        for (int i = 0; i < position.size(); i++)
        {
            float time = cars[i].second;
            // If the current car's time is greater than the time at the top of the stack,
            // it means the current car cannot catch up to the car fleet ahead, thus it forms a new fleet.
            while (!st.empty() && time >= st.top())
            {
                st.pop();
            }
            st.push(time);
        }

        // The size of the stack represents the number of car fleets
        return st.size();
    }
};
