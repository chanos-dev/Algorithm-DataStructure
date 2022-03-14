using System;
using System.Collections.Generic;

public class Kata
{
  private static string GetBit(uint ip)
  {
      List<uint> bits = new List<uint>();

      while(ip != 0)
      {
          bits.Add(ip % 2);
          ip /= 2;
      }
      bits.Reverse();
      return string.Join("", bits);
  }

  private static string GetDec(char[] bit)
  {
      uint b = 0;
      uint s = (uint)Math.Pow(2, bit.Length-1);

      for(int i=0; i<bit.Length; i++)
      {
          if (bit[i] == '1')
          {
              b += s;
          }

          s /= 2;
      }

      return b.ToString();
  }

  public static string UInt32ToIP(uint ip)
  {
      var ipTobit = GetBit(ip);

      if (ipTobit.Length < 32)
      {
          var z = string.Empty;
          for(int i=0; i< (32 - ipTobit.Length); i++)
              z += "0";

          ipTobit = z + ipTobit;
      }

      char[] bit = new char[8];
      List<string> ans = new List<string>();
      int s = 0;
      for(int i=0; i<ipTobit.Length; i++)
      {
          bit[s++] = ipTobit[i];

          if (s == 8)
          {
              s = 0;
              ans.Add(GetDec(bit));
          }
      }

      return string.Join(".", ans);
  }
}