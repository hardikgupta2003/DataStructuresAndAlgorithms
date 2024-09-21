#include <iostream>
using namespace std;

  bool checkPalindrome(string s,int start,int end){
        
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
            
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                bool s1=checkPalindrome(s,start+1,end);
                bool s2=checkPalindrome(s,start,end-1);
                return s1||s2;
            }
        }
        return true;
    }

    int main(){
        string s="abca";
    
       bool ans=  validPalindrome(s);
       cout<<ans;
        return 0;
    }