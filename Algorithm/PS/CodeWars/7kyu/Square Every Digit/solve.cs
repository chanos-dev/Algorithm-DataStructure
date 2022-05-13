using System;
using System.Linq;

public class Kata
{
    public static int SquareDigits(int n)
    {
        return int.Parse(string.Join("", n.ToString().Select(s => Math.Pow(s - '0', 2))));
    }
}