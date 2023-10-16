#include<iostream>
using namespace std;

void Subsequences(string &str,string output,int index){
    //base case
    if(index>=str.length()){
        cout<<output<<endl;
        return ;
    }
    char ch=str[index];
    //include
    
    Subsequences(str,output,index+1);

    //exclude
    output.push_back(ch);
    Subsequences(str,output,index+1);
    // //include
    // output.push_back(ch);
    // Subsequences(str,output,index+1);

    // //exclude
    // output.pop_back();
    // Subsequences(str,output,index+1);



}
int main(){
    string str="abc";
    int index=0;
    string output="";

    Subsequences(str,output,index);
  





    return 0;
}