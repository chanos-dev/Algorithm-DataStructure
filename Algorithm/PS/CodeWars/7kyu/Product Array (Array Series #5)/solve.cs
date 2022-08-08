class Kata
{
    public static int[] ProductArray(int[] array)
    {
        int s = 1;
        int[] ans = new int[array.Length];
        for (int i = 0; i < array.Length; i++)
            s *= array[i];

        for (int i = 0; i < array.Length; i++)
            ans[i] = s / array[i];

        return ans;
    }
}