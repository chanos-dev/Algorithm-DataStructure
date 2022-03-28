using System;

public class PyramidSlideDown
{
    public static int LongestSlideDown(int[][] pyramid)
    {
        int[,] sumPyramid = new int[pyramid.GetLength(0), pyramid.GetLongLength(0)];
        sumPyramid[0, 0] = pyramid[0][0];
        int ans = -1;
        for (int r = 0; r < pyramid.GetLength(0) - 1; r++)
        {
            for (int c = 0; c < pyramid[r].Length; c++)
            {
                int downo = sumPyramid[r, c] + pyramid[r + 1][c];
                int downt = sumPyramid[r, c] + pyramid[r + 1][c + 1];

                if (sumPyramid[r + 1, c] < downo)
                    sumPyramid[r + 1, c] = downo;

                if (sumPyramid[r + 1, c + 1] < downt)
                    sumPyramid[r + 1, c + 1] = downt;

                ans = Math.Max(Math.Max(ans, downo), downt);
            }
        }

        return ans;
    }
}