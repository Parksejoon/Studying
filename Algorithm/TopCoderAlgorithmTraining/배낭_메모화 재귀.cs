using System;
using System.Collections.Generic;

namespace Studying_CS
{
    class 배낭_메모화_재귀
    {
        int[] ws = new int[] { 3, 4, 1, 2, 3 };
        int[] ps = new int[] { 2, 3, 2, 3, 6 };
        int maxw = 10;
        int[,] dp = new int[6, 11];

        int knapsack(int n, int w)
        {
            if (w > maxw) return -1;
            if (n >= ws.Length) return 0;
            if (dp[n, w] >= 0) return dp[n, w];
            return dp[n, w] = Math.Max(knapsack(n + 1, w), knapsack(n + 1, w + ws[n]) + ps[n]);
        }
    }
}
