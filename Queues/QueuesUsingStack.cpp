#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (!s2.empty())
        {
            int top = s2.top();
            s2.pop();
            return top;
        }
        else
        {
            while (!s1.empty())
            {
                int top = s1.top();
                s1.pop();
                s2.push(top);
            }
            int top = s2.top();
            s2.pop();
            return top;
        }
    }

    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                int top = s1.top();
                s1.pop();
                s2.push(top);
            }
            return s2.top();
        }
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */