using System.Linq;

public class Kata
{
    public static int PositiveSum(int[] arr)
    {
        return arr.Sum(a => a > 0 ? a : 0);
    }
}