using System;
using System.Text;

public class Diamond
{
    public static string print(int n)
    {
        if (n <= 0 || n % 2 == 0) return null;

        StringBuilder sb = new StringBuilder();

        int start = n / 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - start; j++)
            {
                if (j < start) sb.Append(" ");
                else sb.Append("*");
            }

            if (i < n / 2) start--;
            else start++;

            sb.Append("\n");
        }

        return sb.ToString();
    }
}