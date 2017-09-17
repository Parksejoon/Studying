using System;
using System.Collections.Generic;

class BadNeightbors
{
    public int maxDonations(int[] donations)
    {
        int ans = 0;
        int leng = donations.Length;
        int[] dp = new int[leng];

        for (int i = 0; i < leng - 1; i++)
        {
            dp[i] = donations[i];
            if (i > 0) dp[i] = Math.Max(dp[i], dp[i - 1]);
            if (i > 1) dp[i] = Math.Max(dp[i], dp[i - 2] + donations[i]);
            ans = Math.Max(ans, dp[i]);
        }

        for (int i = 0; i < leng - 1; i++)
        {
            dp[i] = donations[i + 1];
            if (i > 0) dp[i] = Math.Max(dp[i], dp[i - 1]);
            if (i > 1) dp[i] = Math.Max(dp[i], dp[i - 2] + donations[i + 1]);
            ans = Math.Max(ans, dp[i]);
        }

        return ans;
    }
}
