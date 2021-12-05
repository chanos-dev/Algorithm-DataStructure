using System;
using System.Collections.Generic;
using System.Text;

class _11656
{
    static void Main()
    {
        string s = Console.ReadLine();
        List<string> sl = new List<string>(1000);

        for(int i=0; i<s.Length; i++)
        {
            sl.Add(s.Substring(i, s.Length - i));
        }

        sl.Sort();

        StringBuilder sb = new StringBuilder();
        foreach(var v in sl)
        {
            sb.AppendLine(v);
        }

        Console.WriteLine(sb);
    }
}