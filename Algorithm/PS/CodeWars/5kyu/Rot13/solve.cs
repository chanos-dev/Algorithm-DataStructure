using System.Collections.Generic;

public class Kata
{
  public static string Rot13(string message)
  {
    List<char> c = new List<char>(message.Length);

    foreach (var m in message)
    {
        if ((m >= 'a' && m <= 'z') ||
            (m >= 'A' && m <= 'Z'))
        {
            if (m < 91)
            {
                var p = m + 13;

                if (p > 90)
                    c.Add((char)(65 + (p - 91)));
                else
                    c.Add((char)(p));
            }
            else
            {
                var p = m + 13;

                if (p > 122)
                    c.Add((char)(97 + (p - 123)));
                else
                    c.Add((char)(p));
            }
        }
        else
        {
            c.Add(m);
        }
    }

    return string.Join("", c);
  }
}