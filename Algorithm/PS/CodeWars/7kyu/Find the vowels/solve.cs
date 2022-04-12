using System.Collections.Generic;
using System.Linq;

public class Kata
{
    public static int[] VowelIndices(string word)
    {
        List<int> ans = new List<int>();
        var vowels = new[]
        {
            'a',
            'e',
            'i',
            'o',
            'u',
            'y',
        };
        word = word.ToLower();
        for (int idx = 0; idx < word.Length; idx++)
        {
            if (vowels.Contains(word[idx]))
                ans.Add(idx+1);
        }

        return ans.ToArray();
    }
}