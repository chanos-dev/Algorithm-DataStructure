using System;
using System.Linq;
public static class Kata
{
    public static long RowSumOddNumbers(long n)
    {
        int t = Enumerable.Range(1, (int)n).Sum() * 2 - 1;
        long ans = 0;
        for (int i = 0; i < (int)n; i++, t -= 2)
            ans += t;
        return ans;
    }
}