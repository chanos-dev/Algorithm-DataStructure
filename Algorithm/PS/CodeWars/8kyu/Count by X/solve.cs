using System;
using System.Collections.Generic;

public static class Kata
{
    public static int[] CountBy(int x, int n)
    {
        List<int> ans = new List<int>();
        for (int v = x; ans.Count < n; v += x)
            ans.Add(v);
        return ans.ToArray();
    }
}