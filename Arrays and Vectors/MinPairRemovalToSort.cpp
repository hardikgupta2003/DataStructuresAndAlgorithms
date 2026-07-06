class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        if (is_sorted(nums.begin(), nums.end()))
        {
            return 0;
        }
        int count = 0;

        while (!is_sorted(nums.begin(), nums.end()))
        {
            int minPairSum = INT_MAX;
            int index = -1;
            int n = nums.size();

            for (int i = 0; i < n - 1; i++)
            {
                int pairSum = nums[i] + nums[i + 1];
                if (pairSum < minPairSum)
                {
                    minPairSum = pairSum;
                    index = i;
                }
            }
            count++;

            nums[index] += nums[index + 1];
            nums.erase(nums.begin() + index + 1);
        }
        return count;
    }
};