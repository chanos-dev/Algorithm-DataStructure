using System.Collections.Generic;
using System.Linq;

public class Kata
{
    public static string AverageString(string str)
    {
        if (string.IsNullOrEmpty(str)) return "n/a";

        Dictionary<string, int> number = new Dictionary<string, int>()
            {
                { "zero", 0 },
                { "one", 1 },
                { "two", 2 },
                { "three", 3 },
                { "four", 4 },
                { "five", 5 },
                { "six", 6 },
                { "seven", 7 },
                { "eight", 8 },
                { "nine", 9 },
            };

        var items = str.Split(' ');
        var convert = items.Select(item =>
        {
            if (!number.ContainsKey(item))
                return -1;

            return number[item];
        }).ToArray();

        if (convert.Any(c => c == -1)) return "n/a";

        var result = convert.Sum() / convert.Length;
        foreach (var key in number.Keys)
        {
            if (number[key] == result)
                return key;
        }

        return "n/a";
    }
}