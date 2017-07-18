using System;
using System.Collections.Generic;

class Cryptography
{
    public long encrypt(int[] numbers)
    {
        long result = 1;

        Array.Sort(numbers);
        numbers[0]++;

        foreach(int i in numbers)
        {
            result *= numbers[i];
        }

        return result;
    }
}
