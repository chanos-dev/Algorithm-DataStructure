public class DecTools
{
    public static int Digits(ulong n)
    {
        if (n == 0)
            return 1;

        int ans = 0;
        while (n > 0)
        {
            ans++;
            n /= 10;
        }
        return ans;
    }
}