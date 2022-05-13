using System;
using System.Linq;

public static class Kata
{
    public static string HighAndLow(string numbers)
    {
        var items = numbers.Split(' ').Select(n => int.Parse(n)).ToArray();
        Array.Sort(items);
        return $"{items[items.Length - 1]} {items[0]}";
    }
}