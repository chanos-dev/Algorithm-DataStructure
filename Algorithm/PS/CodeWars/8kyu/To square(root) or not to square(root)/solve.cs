using System;

public class Kata
{
    public static int[] SquareOrSquareRoot(int[] array)
    {
        for (int idx = 0; idx < array.Length; idx++)
        {
            double n = Math.Sqrt(array[idx]);
            if (n % 1 == 0)
                array[idx] = (int)n;
            else
                array[idx] = (int)Math.Pow(array[idx], 2);
        }

        return array;
    }
}