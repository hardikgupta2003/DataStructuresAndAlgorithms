#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionAddition(string expr)
    {
        int nume = 0;
        int deno = 1;

        int i = 0;
        int n = expr.size();
        while (i < n)
        {
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');

            if (expr[i] == '+' || expr[i] == '-')
            {
                i++;
            }
            // build the currNume
            while (i < n && isdigit(expr[i]))
            {
                int val = expr[i] - '0';
                currNume = (currNume * 10) + val;
                i++;
            }
            // numerator / denominator   // skipping divisor char '/'
            if (expr[i] == '/')
                i++;

            if (isNeg == true)
            {
                currNume *= -1;
            }

            // build the currDeno
            while (i < n && isdigit(expr[i]))
            {
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }
        // num
        // deno
        // -3 / 6 // gcd : 3
        int GCD = abs(__gcd(nume, deno)); // abs : gcd of negative will give negative output
        nume /= GCD;                      //-1
        deno /= GCD;                      // 2

        return to_string(nume) + "/" + to_string(deno); //-1 / 2
    }
};