public static class Kata
{
    public static int[] Incrementer(int[] numbers)
    {
        var ans = new int[numbers.Length];
        for (int i = 0; i < numbers.Length; i++)
            ans[i] = (numbers[i] + i + 1) % 10;
        return ans;
    }
}