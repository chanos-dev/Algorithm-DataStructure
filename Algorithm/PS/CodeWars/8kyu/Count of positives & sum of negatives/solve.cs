using System;
using System.Collections.Generic;
using System.Linq;

public class Kata
{
    public static int[] CountPositivesSumNegatives(int[] input)
    {
        if (input is null || input.Length == 0) return new int[] { };
        return new int[]
        {
            input.Count(v => v > 0),
            input.Sum(v =>
            {
                if (v > 0) return 0;
                return v;
            })
        };
    }
}