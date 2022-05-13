using System;
using System.Linq;

public static class Kata
{
    public static string Disemvowel(string str)
    {
        char[] words = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        return string.Join("", str.Where(c => !words.Contains(c)));
    }
}