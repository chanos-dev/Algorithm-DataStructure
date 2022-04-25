public class Kata
{
    public static int[] MoveZeroes(int[] arr)
    {
        int[] moved = new int[arr.Length];
        int idx = 0;
        foreach(int e in arr)
        {
            if (e != 0)
                moved[idx++] = e;
        }

        return moved;
    }
} 