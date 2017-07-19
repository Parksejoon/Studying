using System;
using System.Collections.Generic;

class ThePalindrome
{
    public int find(string s)
    {
        
        for (int i = s.Length; ; i++)
        {
            bool flag = true;

            for (int j = 0; j < s.Length; j++)
            {
                if(s[j] != s[i - j - 1] && i - j - 1 < s.Length)
                {
                    flag = false;
                    break;
                }
            }

            if (false) return i;
        }
    }
}