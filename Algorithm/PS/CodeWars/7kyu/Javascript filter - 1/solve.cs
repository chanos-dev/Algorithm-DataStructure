using System;
using System.Collections.Generic;
public class Kata
{
    public static string[][] search_names(string[][] logins)
    {
        List<string[]> ans = new List<string[]>();

        for (int i = 0; i < logins.GetLength(0); i++)
        {
            foreach (char c in logins[i][0])
            {
                if (c == '_')
                {
                    ans.Add(logins[i]);
                    break;
                }
            }
        }

        return ans.ToArray(); 
    } 
}