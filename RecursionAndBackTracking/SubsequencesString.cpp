#include<iostream>
using namespace std;

void Subsequences(string &str,string output,int index,int &count){
    //base case
    if(index>=str.length()){
        cout<<output<<endl;
        count++;
        cout<<"count: "<<count<<endl;
        return ;
    }
    char ch=str[index];
    //exclude
    
  Subsequences(str,output,index+1,count);

    //include
    output.push_back(ch);
    Subsequences(str,output,index+1,count);




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
    int count=0;

   Subsequences(str,output,index,count);

  





    return 0;
}