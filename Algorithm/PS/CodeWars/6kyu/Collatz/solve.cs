using System.Collections.Generic;
public class Kata
{
    public static string Collatz(int n)
    {
        List<int> ans = new List<int>();
        while (n != 1)
        {
            ans.Add(n);
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
        }
        ans.Add(1);
        return string.Join("->", ans);
    }
}