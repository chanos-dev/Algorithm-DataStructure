using System;
using System.Collections.Generic;
using System.Linq;

public static class Kata
{
  public static string Order(string words)
  {
    List<string> items = words.Split(' ').ToList();
    items.Sort(delegate(string a, string b)
    {
        char ai = a.Where(ac => ac >= '0' && ac <= '9').First();
        char bi = b.Where(bc => bc >= '0' && bc <= '9').First();

        return ai.CompareTo(bi);
    });

    return string.Join(" ", items);
  }
}