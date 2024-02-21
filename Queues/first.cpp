#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue<int> qs;
    qs.push(10);
    qs.push(40);
    qs.push(30);
    cout<<qs.size()<<endl;
    cout<<qs.back()<<endl;
    cout<<qs.front()<<endl;
    cout<<qs.empty()<<endl;

}