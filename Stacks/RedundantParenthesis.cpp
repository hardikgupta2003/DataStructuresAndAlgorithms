#include <iostream>
#include <stack>
using namespace std;

bool redundantBraces(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (ch == '(' || ch == '*' || ch == '/' || ch == '+' || ch == '-'){
                st.push(ch);
                
            }
            else if(ch == ')'){
                    int countOp=0;
                while(!st.empty() && st.top() != '('){
                    char temp = st.top();
                    if(temp == '*' || temp == '/' || temp == '+' || temp == '-'){
                        countOp++;
                    }
                    st.pop();
            }
            st.pop();

            if(countOp==0){
                return true;
            }
 
        }
    }
    return false;
}

int main(){
    // your code goes here
    string s = "(a+(b*c))";
    
    cout << ((redundantBraces(s)) ? "redundantBraces present" : " redundantBraces Not present");
    
    return 0;
}
    