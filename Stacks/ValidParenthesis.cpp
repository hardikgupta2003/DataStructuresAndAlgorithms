#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '{' || ch == '(' || ch == '[') {
                st.push(ch);
            } else {
                if (!st.empty()) {
                    if (st.top() == '{' && ch == '}') {
                        st.pop();
                    } else if (st.top() == '(' && ch == ')') {
                        st.pop();
                    } else if (st.top() == '[' && ch == ']') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (st.size() == 0) {
            return true;
        } else {
            return false;
        }
    }


int main(){
    // your code goes here
    string s = "{[]}";
    
    cout << ((isValid(s)) ? "Balanced" : "Not Balanced");
    
    return 0;
}
    