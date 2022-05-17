public class Pentanacci
{
    public static long CountOddPentaFib(long n)
    {

        var arr = new ulong[n + 1];
        arr[0] = 0;
        arr[2] = arr[1] = 1;
        arr[3] = 2;
        arr[4] = 4;

        long odd = 1;
        for (int i = 5; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4] + arr[i - 5];
            if ((arr[i] & 1) > 0) odd++;
        }

        return odd;
    }
}