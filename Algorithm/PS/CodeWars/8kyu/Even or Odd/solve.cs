using System;

namespace Solution
{
    public class SolutionClass
    {
        public static string EvenOrOdd(int number)
        {
            return (number & 1) == 1 ? "Odd" : "Even";
        }
    }
}