// leetcode easy
// isomporphic strings
// code
#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     bool isIsomorphic(string s, string t)
//     {
//         if (s.size() != t.size())
//             return false;
//         unordered_map<char, char> map;
//         unordered_set<char> set;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (map.find(s[i]) != map.end())
//             {
//                 if (map[s[i]] != t[i])
//                     return false;
//             }
//             else
//             {
//                 if (set.find(t[i]) != set.end())
//                     return false;
//                 map[s[i]] = t[i];
//                 set.insert(t[i]);
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    void createMapping (string &str){
        char start='a';
        int mapping[300]={0};
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(mapping[ch] == 0){
                mapping[ch]=start;
                start++;
            }
        }

        for(int i=0;i<str.length();i++){
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    bool isIsomorphic(string s, string t) {
       createMapping(s);
       createMapping(t);

       if(s != t){
        return false;
       }
       return true;
    }
};

class Solution
{
public:
    void createMapping(string &str)
    {
        char start = 'a';
        int mapping[300] = {0};
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (mapping[ch] == 0)
            {
                mapping[ch] = start;
                start++;
            }
        }

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    bool isIsomorphic(string s, string t)
    {
        createMapping(s);
        createMapping(t);

        if (s != t)
        {
            return false;
        }
        return true;
    }
};
