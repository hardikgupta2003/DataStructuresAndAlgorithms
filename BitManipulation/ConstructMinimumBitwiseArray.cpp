class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];

            if (num == 2)
            {
                nums[i] = -1;
                continue;
            }

            bool found = false;

            for (int j = 1; j < 32; j++)
            {
                if ((num & (1 << j)) > 0)
                {
                    // bit is set
                    continue;
                }

                int res = (num ^ (1 << (j - 1)));
                found = true;

                nums[i] = res;
                break;
            }

            if (found == false)
            {
                nums[i] = -1;
            }
        }

        return nums;
    }
};