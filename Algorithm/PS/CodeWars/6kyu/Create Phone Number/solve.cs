using System.Linq;

public class Kata
{
    private static string SplitNumbers(int[] numbers, int s, int c)
    {
        return string.Join("", numbers.Skip(s).Take(c));
    }
    public static string CreatePhoneNumber(int[] numbers)
    {
        return $"({SplitNumbers(numbers, 0, 3)}) {SplitNumbers(numbers, 3, 3)}-{SplitNumbers(numbers, 6, 4)}";
    }
}