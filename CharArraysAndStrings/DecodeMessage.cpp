#include <iostream>
using namespace std;


    string decodeMessage(string &key, string &message) {
        char start='a';
        char mapping[300]={0};
        for(int i=0;i<key.length();i++){
            char ch=key[i];
            if(ch != ' ' && mapping[ch]==0){
                mapping[ch]=start;
                start++;
            }
        }

        string ans;
        for(int i=0;i<message.length();i++){
            char ch=message[i];
        
            if(ch==' '){
                ans.push_back(' ');
            }
            else{
                char decodedCh= mapping[ch];
                ans.push_back(decodedCh);
            }
        }
        return ans;
    }

int main(){
    string key="the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    string ans= decodeMessage(key,message);
    for(int i=0;i<ans.length();i++){
        cout<<ans[i];
    }


}