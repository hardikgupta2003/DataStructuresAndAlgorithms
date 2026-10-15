
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> productArrayPrefix(n);
        vector<int> productArraySuffix(n);
        vector<int> ans(n);

        // Prefix[i] = product of all elements before index i
        productArrayPrefix[0] = 1;

        // Suffix[i] = product of all elements after index i
        productArraySuffix[n - 1] = 1;

        // Calculate prefix products from left to right
        for (int i = 1; i < n; i++) {
            productArrayPrefix[i] =
                nums[i - 1] * productArrayPrefix[i - 1];
        }

        // Calculate suffix products from right to left
        for (int i = n - 2; i >= 0; i--) {
            productArraySuffix[i] =
                nums[i + 1] * productArraySuffix[i + 1];
        }

        // Multiply prefix and suffix to exclude nums[i]
        for (int i = 0; i < n; i++) {
            ans[i] = productArrayPrefix[i] * productArraySuffix[i];
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> ans = solution.productExceptSelf(nums);

    cout << "Product array: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
