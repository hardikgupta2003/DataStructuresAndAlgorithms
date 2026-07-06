// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void reverseArr(vector<char> &arr)
{
    if (0 == arr.size())
    {
        return;
    }

    char val = arr[0];
    arr.erase(arr.begin());

    reverseArr(arr);

    arr.push_back(val);
}

int main()
{
    vector<char> arr;
    for (int i = 'a'; i <= 'd'; i++)
    {
        arr.push_back(i);
    }
    for (auto &i : arr)
    {
        cout << i << endl;
    }
    cout<<endl;

    reverseArr(arr);

    for (auto &i : arr)
    {
        cout << i << endl;
    }

    return 0;
}