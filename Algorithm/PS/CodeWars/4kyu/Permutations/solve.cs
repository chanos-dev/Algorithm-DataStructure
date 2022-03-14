using System;
using System.Collections.Generic;
using System.Linq;

class Permutations
{
    private static char[] arr;
    private static List<string> ans;
    private static int len;
    private static string q;
    private static bool[] visted;
    private static void Bac(int k)
    {
        if (k == len)
        {
            var str = string.Join("", arr);
            if (!ans.Contains(str))
                ans.Add(str);                
            return;
        }

        for(int i=0; i< len; i++)
        {
            if (visted[i]) continue;
            visted[i] = true;
            arr[k] = q[i];
            Bac(k + 1);
            visted[i] = false;
        }
    }

    public static List<string> SinglePermutations(string s)
    {
        ans = new List<string>();
        arr = new char[s.Length];
        visted = new bool[s.Length];
        len = s.Length;
        q = s;
        Bac(0);
        return ans.ToList();
    }
}