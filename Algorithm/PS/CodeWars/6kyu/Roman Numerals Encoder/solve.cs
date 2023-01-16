using System;
using System.Linq;

public class RomanConvert
{
    private static readonly char[] Ones = new[] { 'I', 'X', 'C', 'M' };
    private static readonly char[] Fives = new[] { 'V', 'L', 'D', ' ' };

    private static string GetRoman(int n, int l)
    {
        char one = Ones[l - 1];
        char five = Fives[l - 1];

        if (n < 4)
            return string.Join("", Enumerable.Repeat(one, n));
        else if (n == 4)
            return new string(new char[] { one, five });
        else if (n == 5)
            return five.ToString();
        else if (n == 9)
            return new string(new char[] { one, Ones[l] });
        else
            return $"{five}{string.Join("", Enumerable.Repeat(one, n - 5))}";
    }
    public static string Solution(int n)
    {
        string ans = string.Empty;
        int l = 1;
        while (n != 0)
        {
            var v = n % 10;
            ans = GetRoman(v, l++) + ans;
            n /= 10;
        }

        return ans;
    }
}