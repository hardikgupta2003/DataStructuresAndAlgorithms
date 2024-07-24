#include <bits/stdc++.h>
using namespace std;

//front and rear queue concept
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int front = 0;
        int rear = 0;
        int current_gas = 0;

        while (front < n)
        {
            current_gas += gas[rear] - cost[rear];

            if (current_gas < 0)
            {
                // If current gas is negative, we can't start from 'front'
                // Move front to the next station and reset the gas and rear pointer
                front++;
                rear = front;
                current_gas = 0;

                if (front >= n)
                {
                    return -1; // No valid starting point found
                }
            }
            else
            {
                // Move rear to the next station in circular fashion
                rear = (rear + 1) % n;

                // If front catches up to rear, we've found a valid start
                if (rear == front)
                {
                    return front;
                }
            }
        }

        return -1; // No valid circuit completion possible
    }
};

// greedy algo
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int front = 0;
    int rear = 0;
    int current_gas = 0;

    while (front < n) {
        current_gas += gas[rear] - cost[rear];

        if (current_gas < 0) {
            // If current gas is negative, we can't start from 'front'
            // Move front to the next station and reset the gas and rear pointer
            front++;
            rear = front;
            current_gas = 0;

            if (front >= n) {
                return -1; // No valid starting point found
            }
        } else {
            // Move rear to the next station in circular fashion
            rear = (rear + 1) % n;

            // If front catches up to rear, we've found a valid start
            if (rear == front) {
                return front;
            }
        }
    }

    return -1; // No valid circuit completion possible

    }
};

// greedy algorithm
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int balance = 0;
        int deficit = 0;

        // index from where we are starting the movement
        int start = 0;

        // har ek index ko check krna hai , ki vo answer hai ya nahi
        for (int i = 0; i < gas.size(); i++)
        {
            balance = balance + gas[i] - cost[i];

            if (balance < 0)
            {
                deficit += abs(balance);
                start = i + 1;
                balance = 0;
            }
        }

        if (balance - deficit >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};