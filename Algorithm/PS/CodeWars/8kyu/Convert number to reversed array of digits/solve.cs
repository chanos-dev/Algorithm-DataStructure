using System;
using System.Collections.Generic;

namespace Solution
{
    class Digitizer
    {
        public static long[] Digitize(long n)
        {
            if (n == 0) return new long[] { 0 };
            List<long> ans = new List<long>();
            while (n > 0)
            {
                ans.Add(n % 10);
                n /= 10;
            }
            return ans.ToArray();
        }
    }
}