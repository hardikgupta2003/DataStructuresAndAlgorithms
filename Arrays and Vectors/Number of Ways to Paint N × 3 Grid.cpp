class Solution
{
public:
    int numOfWays(int n)
    {
        const long MOD = 1e9 + 7;

        // Base case: n = 1
        long aba = 6; // patterns like R Y R
        long abc = 6; // patterns like R Y G

        for (int i = 2; i <= n; i++)
        {
            long newAba = (aba * 3 + abc * 2) % MOD;
            long newAbc = (aba * 2 + abc * 2) % MOD;

            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % MOD;
    }
};
//Leetcode :1411