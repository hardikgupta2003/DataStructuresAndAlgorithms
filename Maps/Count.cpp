#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s = "aabbccddeew65344w5twret";
    unordered_map<char, int> mp;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        mp[ch]++;
    }

    for (auto it : mp)
    {
        cout << it.first << " : " << it.second << endl;
    }

    return 0;
}