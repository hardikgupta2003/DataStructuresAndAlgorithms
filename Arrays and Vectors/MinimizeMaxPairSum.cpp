class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;

        int s = 0;
        int e = nums.size() - 1;

        while (s < e)
        {
            ans = max(ans, nums[s++] + nums[e--]);
        }
        return ans;
    }
};