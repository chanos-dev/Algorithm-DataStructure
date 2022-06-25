using System;
using System.Collections.Generic;

public class Kata
{
    public static int[] ChoreAssignment(int[] chores)
    {
        List<int> ans = new List<int>();

        Array.Sort(chores);

        for (int h = 0, t = chores.Length - 1; h < chores.Length / 2; h++, t--)
            ans.Add(chores[h] + chores[t]);

        ans.Sort();
        return ans.ToArray();
    }
}