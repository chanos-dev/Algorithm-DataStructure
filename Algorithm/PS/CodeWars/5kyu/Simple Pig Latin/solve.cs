using System;
using System.Linq;

public class Kata
{
  public static string PigIt(string str)
  {
    return string.Join(" ", str.Split(' ').Select(item =>
    {
        if (!(item[0] >= 'a' && item[0] <= 'z') &&
            !(item[0] >= 'A' && item[0] <= 'Z'))
            return item;

        item = item.Insert(item.Length, $"{item[0]}ay");
        return item.Remove(0, 1);
    })); 
  }
}