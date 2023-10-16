#include <iostream>
#include <vector>
using namespace std;

void createUpdateMapping(string& str){
        //find mapping
        char start='a';
        char mapping[300]={0};

        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(mapping[ch]==0){
                mapping[ch]=start;
                start++;
            }

        }

        //update the string
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            str[i]=mapping[ch];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // firstly normalize the pattern
        createUpdateMapping(pattern);

        for(string s:words){
            string tempString=s;

            createUpdateMapping(tempString);
            if(tempString==pattern){

                ans.push_back(s);
                
            }
        }
        
        return ans;
    }


    int main(){

        string pattern="abc";
        vector<string> words{"abc","deq","mee","dqq","dkd","ccc"};
        findAndReplacePattern(words,pattern);
        

        return 0;
    }