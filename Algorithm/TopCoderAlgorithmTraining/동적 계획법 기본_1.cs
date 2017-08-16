using System;
using System.Collections.Generic;

namespace Studying_CS
{
    class 동적계획법_1
    {
        const int h = 5, w = 4;
        int[,] dp = new int[h + 1, w + 1];

        int dfs(int nowh, int noww)
        {
            if (noww > w || nowh > h) return 0;
            if (noww == w || nowh == h) return 1;
            if (dp[nowh, noww] != 0) return dp[nowh, noww];
            return dp[nowh, noww] = dfs(nowh + 1, noww) + dfs(nowh, noww + 1);
        }
    }
}
