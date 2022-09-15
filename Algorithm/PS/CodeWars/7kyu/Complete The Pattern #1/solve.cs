using System;
using System.Linq;
using System.Collections.Generic;
public class Kata
{
    public string Pattern(int n)
    {
        if (n < 1) return string.Empty;
        List<string> ans = new List<string>();
        Enumerable.Range(1, n).ToList().ForEach(n => ans.Add(string.Join("", Enumerable.Repeat(n, n))));
        return string.Join("\n", ans);
    }
}