#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
public:
    stack<string> browserStack, fwdStack;
    BrowserHistory(string homepage)
    {
        browserStack.push(homepage);
    }

    void visit(string url)
    {
        // before visiting , we have to clear fwd history
        while (!fwdStack.empty())
        {
            fwdStack.pop();
        }
        browserStack.push(url);
    }

    string back(int steps)
    {
        while (steps--)
        {
            if (browserStack.size() > 1)
            {
                fwdStack.push(browserStack.top());
                browserStack.pop();
            }
            else
            {
                // only homepage is present now
                // back not possible
                break;
            }
        }
        return browserStack.top();
    }

    string forward(int steps)
    {
        while (steps--)
        {
            if (!fwdStack.empty())
            {
                browserStack.push(fwdStack.top());
                fwdStack.pop();
            }
            else
            {
                break;
            }
        }
        return browserStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */