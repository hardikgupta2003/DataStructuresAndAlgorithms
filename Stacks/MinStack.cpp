#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<pair<int, int>> st;
    MinStack() {}

    void push(int val) {
        pair<int, int> p;
        // first element
        if (st.size() == 0) {
            p.first = val;
            p.second = val;
            st.push_back(p);
            cout<<"first: "<<p.first<<" "<<"second: "<<p.second<<endl;
            // cout<<st.top()<<endl;
        }
        // pushing element after first element
        else {
            p.first = val;
            int oldMin = st.back().second;
            p.second = min(val,oldMin);
            st.push_back(p);
            cout<<"first: "<<p.first<<" "<<"second: "<<p.second<<endl;
        }
    }

    void pop() {
        st.pop_back();
    }

    int top() {
       return st.back().first;
    }

    int getMin() {
       return st.back().second;
    }
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(5);
    obj->push(3);
    obj->push(2);
    obj->push(1);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}
  
