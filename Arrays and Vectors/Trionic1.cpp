class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 4)
            return false;

        int i = 1;

        // 1️⃣ strictly increasing
        while (i < n && nums[i] > nums[i - 1])
            i++;
        if (i == 1 || i == n)
            return false;

        // 2️⃣ strictly decreasing
        while (i < n && nums[i] < nums[i - 1])
            i++;
        if (i == n)
            return false;

        // 3️⃣ strictly increasing
        while (i < n && nums[i] > nums[i - 1])
            i++;

        return i == n;
    }
};

class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        if (nums.size() <= 3)
            return false;

        int firstIndex = -1;
        int secondIndex = -1;
        int thirdIndex = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                firstIndex = i;
            }
            else
            {
                break;
            }
        }

        if (firstIndex != -1)
        {
            for (int i = firstIndex + 1; i < nums.size(); i++)
            {
                if (nums[i] < nums[i - 1])
                {
                    secondIndex = i;
                }
                else
                {
                    break;
                }
            }
        }

        if (secondIndex != -1)
        {
            for (int i = secondIndex + 1; i < nums.size(); i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    thirdIndex = i;
                }
                else
                {
                    break;
                }
            }
        }

        return thirdIndex == nums.size() - 1;
    }
};