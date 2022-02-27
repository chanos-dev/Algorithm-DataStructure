using System;
using System.Collections.Generic;
using System.Linq;

public class Mixing 
{
  public static string Mix(string s1, string s2)
  {
      int[] al1 = Split(s1);
      int[] al2 = Split(s2);

      List<string> ans = new List<string>();

      for (int i=0; i<26; i++)
      {
          if (al1[i] == al2[i] && al1[i] > 1)
          {
              ans.Add($"3:{string.Join("", Enumerable.Repeat((char)('a' + i), al1[i]))}");
          }
          else
          {
              int m = Math.Max(al1[i], al2[i]);
              if (m < 2) continue;

              if (al1[i] > al2[i])
              {
                  ans.Add($"1:{string.Join("", Enumerable.Repeat((char)('a' + i), m))}");
              }
              else
              {
                  ans.Add($"2:{string.Join("", Enumerable.Repeat((char)('a' + i), m))}");
              }
          }
      }

      ans.Sort(delegate (string a, string b)
      {
          string[] items1 = a.Split(':');
          string[] items2 = b.Split(':');

          if (items1[1].Length == items2[1].Length)
          {
              return string.Compare(items1[0], items2[0]);
          }
          else if (items1[1].Length > items2[1].Length)
          {
              return string.Compare(items1[1], items2[1]) * -1;
          }
          else if (items1[1].Length < items2[1].Length)
          {
              return string.Compare(items1[1], items2[1]);
          }

          return 0;
      });

      return string.Join("/", ans).Replace("3","=");
  }

  public static int[] Split(string s)
  {
      int[] al = new int[26];

      for (int i = 0; i < s.Length; i++)
      {
          if (s[i] >= 'a' && s[i] <= 'z')
              al[s[i] - 'a']++;
      }

      return al;
  }
}