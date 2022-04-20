using System;
public class CountIPAddresses
{
    public static long IpsBetween(string start, string end)
    {
        int[] startItems = new int[4];
        int[] endItems = new int[4];

        int idx = 0;
        foreach (string s in start.Split('.'))
            startItems[idx++] = int.Parse(s);

        idx = 0;
        foreach (string s in end.Split('.'))
            endItems[idx++] = int.Parse(s);


        for (idx = endItems.Length-1; idx >= 0 ; idx--)
        {  
            if (startItems[idx] > endItems[idx])
            {
                endItems[idx - 1]--;
                endItems[idx] += 256;
            }

            endItems[idx] -= startItems[idx];
        }

        long sum = 0;

        for (idx = endItems.Length - 1; idx >= 0; idx--)
        { 
            sum += (long)(endItems[idx] * Math.Pow(256, Math.Abs(idx - 3)));
        }

        return sum;
    }
}