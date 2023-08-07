using System;
using System.Collections.Generic;

public static class Kata
{
    public static string GroupByCommas(int n)
    {
        Stack<char> stk = new Stack<char>();
        int comma = 0;
        while (n != 0)
        {
            int t = n % 10;
            comma++;
            stk.Push((char)(t + 48));
            n /= 10;
            if (n > 0 && comma == 3)
            {
                stk.Push(',');
                comma = 0;
            }
        }

        return string.Join("", stk);
    }
}