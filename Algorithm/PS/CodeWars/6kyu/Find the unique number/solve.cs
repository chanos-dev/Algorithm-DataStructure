using System.Collections.Generic;
using System.Linq;

public class Kata
{
    public static int GetUnique(IEnumerable<int> numbers)
    {
        var n = numbers.OrderBy(n => n).ToArray();

        if (n[0] != n[1])
            return n[0];

        return n[n.Length - 1];
    }
}