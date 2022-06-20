using System;
using System.Collections.Generic;
using System.Linq;

public class CaesarCipher
{
    public static List<string> movingShift(string s, int shift)
    {
        int div = (int)Math.Ceiling((double)s.Length / 5);
        var moving = new List<List<char>>();
        var splitItems = new List<char>();

        for (int i = 0; i < s.Length; i++)
        {
            var a = s[i] >= 97 ? 97 : 65;
            var c = (s[i] - a + shift++) % 26;

            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z'))
                splitItems.Add((char)(c + a));
            else
                splitItems.Add(s[i]);

            if ((i % div) == div - 1)
            {
                moving.Add(splitItems);
                splitItems = new List<char>();
            }
        }
        moving.Add(splitItems);

        return moving.Select(m => string.Join("", m)).ToList();
    }

    public static string demovingShift(List<string> s, int shift)
    {
        List<char> plain = new List<char>();

        foreach (var chiper in s)
        {
            for (int i = 0; i < chiper.Length; i++)
            {
                var a = chiper[i] >= 97 ? 97 : 65;
                var c = (chiper[i] - a - shift++) % 26;

                if ((chiper[i] >= 'a' && chiper[i] <= 'z') ||
                    (chiper[i] >= 'A' && chiper[i] <= 'Z'))
                {
                    if (c >= 0)
                        plain.Add((char)(c + a));
                    else
                        plain.Add((char)(c + a + 26));
                }
                else
                    plain.Add(chiper[i]);
            }
        }

        return string.Join("", plain);
    }
}