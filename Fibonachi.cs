using System;

namespace BrainCSharp
{
    class MainApp
    {
        static int Fibonachi(int n)
        {
            if (n < 2)
                return n;
            else
                return Fibonachi(n - 1) + Fibonachi(n - 2);
        }
        
        static void Main()
        {
            Console.WriteLine("숫자를 입력행 !");
            int n = Convert.ToInt32(Console.ReadLine());
        }
    }
}