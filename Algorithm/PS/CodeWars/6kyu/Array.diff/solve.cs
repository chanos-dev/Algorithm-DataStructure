using System;
using System.Collections.Generic;
using System.Linq;

public class Kata
{
  public static int[] ArrayDiff(int[] a, int[] b)
  {
    List<int> l = new List<int>();

    for (int i = 0; i < a.Length; i++)
    {
        if (b.Contains(a[i])) continue;
        l.Add(a[i]);
    }

    return l.ToArray();
  }
}