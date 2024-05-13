public static class Kata
{
    public static int SquareSum(int[] numbers)
    {
        return numbers.Sum(n => (int)Math.Pow(n, 2));
    }
}