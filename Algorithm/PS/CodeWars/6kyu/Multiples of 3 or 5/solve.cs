using System.Linq;

public static class Kata
{
    public static int Solution(int value)
    {
        int ans = 0;
        for (int i = 1; i < value; i++)
            if ((i % 3 == 0) || (i % 5 == 0)) ans += i;
        return ans;
    }
}