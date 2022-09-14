using System;
public class Kata
{
    public static double Index(int[] array, int n)
    {
        if (array.Length <= n) return -1;
        return Math.Pow(array[n], n);
    }
}