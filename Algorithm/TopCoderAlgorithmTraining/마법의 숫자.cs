using System;
using System.Collections.Generic;

public class NumberMagicEasy
{
    static void Main()
    {
        int result = theNumber(Console.ReadLine());
        Console.WriteLine(result);
    }

    public static int theNumber(string answer)
    {
        string[] arr =
        {
            "YYYY",
            "YYYN",
            "YYNY",
            "YYNN",
            "YNYY",
            "YNYN",
            "YNNY",
            "YNNN",
            "NYYY",
            "NYYN",
            "NYNY",
            "NYNN",
            "NNYY",
            "NNYN",
            "NNNY",
            "NNNN"
        };

        for (int i = 0; i < 16; i++)
        {
            if (arr[i] == answer) return i + 1;
        }

        return 0;
    }
}
