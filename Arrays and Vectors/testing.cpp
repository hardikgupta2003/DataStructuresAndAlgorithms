#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size() - 1;
    while (n >= 0)
    {
        int carry = 0;
        int ans = digits[n] + carry + 1;
        cout<<ans<<endl;
        if (ans > 9)
        {
            carry = ans / 10;
            digits[n] = ans % 10;
            if (n == 0) {
                cout<<n<<endl;
                cout<<"print hello: "<<endl;
                digits.insert(digits.begin(), carry);
            }
        }
        else
        {
            digits[n] = ans;
            break;
        }
        n--;
    }
    return digits;
}

int main(){

    vector<int> input = vector<int>{9};
    vector<int> ans = plusOne(input);

    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}