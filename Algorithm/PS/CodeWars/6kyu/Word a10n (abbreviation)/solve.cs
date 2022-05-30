using System.Collections.Generic;
using System.Linq;
public class Abbreviator
{
    public static string Abbreviate(string input)
    {
        string GetAbbreviation(string s)
        {
            if (s.Length < 4)
                return s;

            return $"{s[0]}{s.Length - 2}{s[s.Length - 1]}";
        }

        List<string> ans = new List<string>();
        string[] items = input.Split(' ');

        foreach (string item in items)
        {
            string a = "";
            string t = "";
            foreach (char c in item)
            {
                if (char.IsLetter(c))
                    t += c;
                else
                {
                    a += $"{GetAbbreviation(t)}{c}";
                    t = "";
                }
            }

            ans.Add($"{a}{GetAbbreviation(t)}");
        }

        return string.Join(" ", ans);
    }
}