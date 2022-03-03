using System.Collections.Generic;
using System;

public class RangeExtraction
{
    public static string Extract(int[] args)
    {
        List<string> range = new List<string>();

        int s = args[0];
        int e = args[0];

        for(int i=0; i<args.Length; i++)
        {                 
            if (i < args.Length-1 &&
                args[i]+1 == args[i+1])
            {
                e = args[i + 1];
            }
            else
            {
                if (s == e)
                    range.Add(s.ToString());
                else
                {
                    if (Math.Abs(s-e) == 1)                            
                        range.Add($"{s},{e}");
                    else
                        range.Add($"{s}-{e}");
                }
                if (i == args.Length - 1) break;
                s = args[i + 1];
                e = args[i + 1];
            } 
        } 

        return string.Join(",", range);
    }
}