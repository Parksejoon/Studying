using System;
using System.Collections.Generic;

class InterestingDigits
{
    public int[] digits(int bas)
    {
        List<int> ans = new List<int>();

        bas--;
        for(int i = 2; i <= bas; i++)
        {
            if (bas % i == 0) ans.Add(i);
        }

        return ans.ToArray();
    }
}