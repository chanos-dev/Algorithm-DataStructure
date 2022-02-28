using System.Collections.Generic;
using System.Linq;

public class HumanTimeFormat{
  public static string formatDuration(int seconds){
    List<string> ans = new List<string>();
    int[] time = new int[]
    {
        31536000,
        86400,
        3600,
        60,
        1,
    };

    string[] str = new string[]
    {
        "year",
        "day",
        "hour",
        "minute",
        "second",
    };

    if (seconds == 0) return "now"; 
    int s = 0;
    while(seconds != 0)
    {
        int t = seconds / time[s];
        if (t != 0)
        {
            if (t == 1)
                ans.Add($"{t} {str[s]}");
            else
                ans.Add($"{t} {str[s]}s");
            seconds %= time[s];
        }
        else s++;
    }

    if (ans.Count < 3)
        return string.Join(" and ", ans);
    else
        return $"{string.Join(", ", ans.Take(ans.Count - 1))} and {ans.Last()}";
  }
}