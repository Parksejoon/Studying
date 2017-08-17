using System;
using System.Collections.Generic;

namespace Studying_CS
{
    class 배낭_동적계획법
    {
        int[] ws = { 3, 4, 1, 2, 3 };
        int[] ps = { 2, 3, 2, 3, 6 };
        int maxw = 10;
        int[,] dp = new int[6, 11];
        int ret = 0;
        
        void knapsack()
        {
            for (int i = 0; i <= ws.Length; i++)
            {
                for (int j = 0; j <= maxw; j++)
                {
                    if (j + ws[i] <= maxw)
                    {
                        dp[i + 1, j + ws[i]] = Math.Max(dp[i + 1, j + ws[j]], dp[i, j] + ps[i]);
                        ret = Math.Max(dp[i + 1, j + ws[i]], ret);
                    }
                }
            }
        }
    }
}
