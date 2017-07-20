using System;
using System.Collections.Generic;

class dual
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int cnt = 0;

        Dictionary<string, int> arr = new Dictionary<string, int>
        {
            { "gold", 0 },
            { "mana", 0 },
            { "light", 0 },
            { "dark", 0 },
            { "nature", 0 }
        };
        
        for (int i = 0; i < n; i++)
        {
            string temp = Console.ReadLine();

            arr[temp]++;
        }
        
        foreach(KeyValuePair<string, int> key in arr)
        {
            if (arr[key.Key] != 0) cnt++;
        }

        if (cnt > 3) Console.WriteLine("invalid");
        else Console.WriteLine("valid");

        return;
    }
}
