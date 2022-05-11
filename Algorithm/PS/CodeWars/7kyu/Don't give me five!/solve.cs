using System.Linq;

public class Kata
{
    private static bool CheckFive(int v)
    {
        while (v! = 0)
        {
            if (v % 10 == 5 || v % 10 == -5) return true;
            v /= 10;
        }
        return false;
    }

    public static int DontGiveMeFive(int start, int end)
    {
        return Enumerable.Range(start, end - start + 1).Count(v => !CheckFive(v));
    }
}