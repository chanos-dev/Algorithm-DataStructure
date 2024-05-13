using System;
public class Kata
{
    public static string FindNeedle(object[] haystack)
    {
        int idx = Array.IndexOf(haystack, "needle");
        return $"found the needle at position {idx}";
    }
}