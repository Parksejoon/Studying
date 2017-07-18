using System;
using System.Collections.Generic;

class InterestingParty
{
    public int bestInvitation(string[] first, string[] second)
    {
        Dictionary<string, int> dic = new Dictionary<string, int>();

        for (int i = 0; i < first.Length; i++)
        {
            dic[first[i]] = 0;
            dic[second[i]] = 0;
        }

        for (int i = 0; i < first.Length; i++)
        {
            dic[first[i]]++;
            dic[second[i]]++;
        }

        int ans = 0;
        foreach(string key in dic.Keys)
        {
            ans = Math.Max(dic[key], ans);
        }

        return ans;
    }
}