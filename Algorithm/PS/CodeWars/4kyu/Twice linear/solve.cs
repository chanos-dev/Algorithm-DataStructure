using System.Collections.Generic;
using System.Linq;

public class DoubleLinear
{ 
    public static int DblLinear(int n)
    {
        List<int> ans = new List<int>()
        {
            1
        };

        int xidx = 0;
        int yidx = 0;

        while (ans.Count <= n)
        {
            int x = ans[xidx] * 2 + 1;
            int y = ans[yidx] * 3 + 1;

            if (x < y)
            {
                ans.Add(x);
                xidx++;
            }
            else if (x > y)
            {
                ans.Add(y);
                yidx++;
            }
            else
            {
                ans.Add(x);
                xidx++; 
                yidx++;
            }
        }

        return ans[n];
    }
}