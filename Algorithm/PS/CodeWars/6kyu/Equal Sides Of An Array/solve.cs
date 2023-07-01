using System.Linq;

public class Kata
{
    public static int FindEvenIndex(int[] arr)
    {
        int totalSum = arr.Sum();
        int startIdx = 0;
        int leftSum = arr[startIdx++];

        if (totalSum - leftSum == 0)
            return 0;

        int ans = -1;

        for (int idx = startIdx; idx < arr.Length; idx++)
        {
            if (leftSum == (totalSum - arr[idx] - leftSum))
                return idx;

            leftSum += arr[idx];
        }

        return ans;
    }
}