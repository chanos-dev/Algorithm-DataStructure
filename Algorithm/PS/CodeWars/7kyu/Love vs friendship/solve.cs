using System;

public static class Kata
{
    public static int WordsToMarks(string str)
    {
        int ans = 0;
        foreach (char c in str) ans += c - 'a';
        return ans + str.Length;
    }
}