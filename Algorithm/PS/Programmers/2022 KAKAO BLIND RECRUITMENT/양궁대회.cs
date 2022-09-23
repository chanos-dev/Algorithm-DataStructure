using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    private const int TARGET = 11;
    private int[] Ans { get; set; } = new int[11];
    private int DiffScore { get; set; } = -1;

    private bool Compare(int[] other)
    {
        for (int i = TARGET - 1; i >= 0; i--)
        {
            if (Ans[i] > other[i]) return false;
            else if (Ans[i] < other[i]) return true;
        }

        return true;
    }

    private void Score(int[] apeachArrows, int[] ryanArrows)
    {
        int apeachScore = 0;
        int ryanScore = 0;
        for (int i = 0, s = 10; i < TARGET; i++, s--)
        {
            if (apeachArrows[i] < ryanArrows[i])
                ryanScore += s;
            else if (apeachArrows[i] > ryanArrows[i])
                apeachScore += s;
        }
        var diff = ryanScore - apeachScore;
        if (DiffScore <= diff && diff > 0)
        {
            if (DiffScore == diff && !Compare(ryanArrows))
                return;

            Ans = ryanArrows.ToArray();
            DiffScore = diff;
        }
    }

    private void dfs(int idx, int arrow, int[] apeachArrows, int[] ryanArrows)
    {
        if (arrow == 0 || idx == TARGET)
        {
            ryanArrows[TARGET - 1] += arrow;
            Score(apeachArrows, ryanArrows);
            ryanArrows[TARGET - 1] -= arrow;
            return;
        }

        if (apeachArrows[idx] < arrow)
        {
            ryanArrows[idx] += apeachArrows[idx] + 1;
            dfs(idx + 1, arrow - ryanArrows[idx], apeachArrows, ryanArrows);
            ryanArrows[idx] -= apeachArrows[idx] + 1;
        }

        dfs(idx + 1, arrow, apeachArrows, ryanArrows);
    }

    public int[] solution(int n, int[] info)
    {
        int[] apeachArrows = info;
        int[] ryanArrows = new int[TARGET];

        dfs(0, n, apeachArrows, ryanArrows);

        if (Ans.All(a => a == 0))
            return new int[] { -1 };
        return Ans;
    }
}