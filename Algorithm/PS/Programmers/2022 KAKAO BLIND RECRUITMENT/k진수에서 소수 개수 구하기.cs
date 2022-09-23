using System;
using System.Linq;

public class Solution {
    private string ConvertValue { get; set; } = string.Empty;

    private bool Prime(long n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        for (int i = 3; i <= Math.Sqrt(n); i += 2)
            if (n % i == 0) return false;

        return true;
    }

    private void Convert(int n, int k)
    {
        if (n <= 0) return;
        ConvertValue += n % k;
        Convert(n / k, k);
    }

    public int solution(int n, int k)
    {
        Convert(n, k);
        ConvertValue = string.Join("", ConvertValue.Reverse());

        int ans = 0;

        var items = ConvertValue.Split(new char[] { '0' }, StringSplitOptions.RemoveEmptyEntries);

        foreach (var item in items)
        {
            if (Prime(long.Parse(item)))
                ans++;
        }

        return ans;
    }
}