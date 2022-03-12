public class Kata
{
  public static string WhatCentury(string year)
  {
    string[] str = new[]
    {
        "st",
        "nd",
        "rd",
    };

    float fy = float.Parse(year) / 100;
    int y = (int)fy;
    y = fy > y ? y + 1 : y;

    if (y < 10 || y > 20)
    {
        int o = y % 10;

        if (o <= 3 && o >= 1)
            return $"{y}{str[o-1]}"; 
    }

    return $"{y}th";
  }
}