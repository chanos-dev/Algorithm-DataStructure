using System;
using System.Linq;

public class Kata
{
    public string Pattern(int n)
    {
        if (n < 1) return string.Empty;
        return string.Join("\n", Enumerable.Range(1, n).Select(e => string.Join("", Enumerable.Range(e, n--).OrderByDescending(x => x))));
    }
}