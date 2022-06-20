public class Kata
{
    public static int[] TwoSum(int[] numbers, int target)
    {
        for (int i = 0; i < numbers.Length - 1; i++)
        {
            for (int j = i + 1; j < numbers.Length; j++)
            {
                if (numbers[i] + numbers[j] == target)
                    return new int[] { i, j };
            }
        }

        return new int[0];
    }
}