using System.Collections.Generic;
using System.Linq;
using System;

public class Kata
{
  public static string SpinWords(string sentence)
  {
      var items = new List<string>();
      var str = string.Empty;

      for(int i=0; i<sentence.Length; i++)
      {
          if (sentence[i] == ' ')
          {
              items.Add(str);
              str = string.Empty;
          }
          else
              str += sentence[i].ToString();
      }

      if (!string.IsNullOrEmpty(str))
          items.Add(str);

      string ans = string.Empty;

      foreach(var item in items)
      {
          if (item.Length >= 5)
          {
              var rev = string.Empty;

              for (int i = item.Length - 1; i >= 0; i--)
                  rev += item[i];

              ans += $"{rev} ";
          }
          else ans += $"{item} ";
      }

      return ans.Trim();
  }
}