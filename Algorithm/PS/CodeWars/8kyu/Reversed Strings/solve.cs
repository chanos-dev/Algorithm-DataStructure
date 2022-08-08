using System;

public static class Kata
{
    public static string Solution(string str)
    {
        string ans = string.Empty;
        for (int idx = str.Length - 1; idx >= 0; idx--)
            ans += str[idx];
        return ans;
    }
}
