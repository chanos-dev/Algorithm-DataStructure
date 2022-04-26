using System.Collections.Generic;

public class Kata
{
    public static string FirstNonRepeatingLetter(string s)
    {
        string lower = s.ToLower();

        Dictionary<char, int> characters = new Dictionary<char, int>();

        foreach (char c in lower)
        {
            if (characters.ContainsKey(c))
                characters[c]++;
            else
                characters.Add(c, 1);
        }

        bool isNone = true;
        int minIdx = s.Length-1;

        foreach(char key in characters.Keys)
        {
            if (characters[key] == 1)
            {
                isNone = false;
                int idx = lower.IndexOf(key);
                if (idx != -1 && idx < minIdx) minIdx = idx;
            }
        } 

        if (isNone) return string.Empty;
        else return s[minIdx].ToString();
    }
}