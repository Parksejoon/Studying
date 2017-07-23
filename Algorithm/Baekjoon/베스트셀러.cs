using System;
using System.Collections.Generic;

namespace maincode
{
    class mainApp
    {
        static void Main()
        {
            Dictionary<string, int> arr = new Dictionary<string, int>();
            int n = int.Parse(Console.ReadLine());
            string[] temp = new string[1000];

            for (int i = 0; i < n; i++)
            {
                temp[i] = Console.ReadLine();
                arr[temp[i]] = 0;
            }

            for (int i = 0; i < n; i++)
            {
                arr[temp[i]]++;
            }

            string big = temp[0];

            foreach (KeyValuePair<string, int> kv in arr)
            {
                if (arr[big] < arr[kv.Key])
                {
                    big = kv.Key;
                }
                else if (arr[big] == arr[kv.Key])
                {
                    if (string.Compare(kv.Key, big) < 0)
                    {
                        big = kv.Key;
                    }
                }
            }

            Console.WriteLine(big);
        }
    }
}