using System;

namespace Solution
{
    public static class Program
    {
        public static int[] reverseList(int[] list)
        {
            int[] ans = new int[list.Length];
            for (int i = 0, j = list.Length - 1; j >= 0; i++, j--)
                ans[i] = list[j];
            return ans;
        }
    }
}