#include <bits/stdc++.h>
using namespace std;
class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        int n = q.size() - 1;
        while (n--)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    int pop()
    {
        int front = q.front();
        q.pop();
        return front;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        if (q.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */