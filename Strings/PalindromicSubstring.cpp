#include<iostream>
using namespace std;


int expand(string s,int i,int j){
        int count=0;

        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;

    }
    int countSubstrings(string s) {
        int totalCount=0;
        for(int center = 0 ; center < s.length(); center++){
            //odd
            int oddAns=expand(s,center,center);
            //even
            int evenAns=expand(s,center,center+1);

            totalCount+=oddAns+evenAns;
        }
        return totalCount;
    }
int main(){
    string s="aaa";
    cout<<countSubstrings(s);



    return 0;
}