using System;
using System.Collections.Generic;
using System.Linq;
namespace Kata
{
    public static class Kata
    {
        public static int[] UpArray(int[] num)
        {
            if (num.Any(n => n < 0 || n >= 10))
                return null;

            if (num.Length == 0)
                return null;

            int lastIdx = num.Length - 1;
            num[lastIdx]++;
            for (int idx = num.Length - 1; idx >= 0; idx--)
            {
                if (num[idx] == 10)
                {
                    num[idx] = 0;

                    if (idx - 1 >= 0)
                        num[idx - 1]++;
                    else
                    {
                        List<int> ans = new(num.Length + 1)
            {
              1
            };
                        ans.AddRange(num);
                        return ans.ToArray();
                    }
                }
            }

            return num;
        }
    }
}