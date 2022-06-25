using System;
using System.Collections.Generic;

public class Dinglemouse
{
    public static int PeakHeight(char[][] mountain)
    {
        int ans = 1;

        var dx = new[] { 0, 1, 0, -1 };
        var dy = new[] { 1, 0, -1, 0 };

        int x = mountain.Length;
        int y = mountain[0].Length;

        int[,] board = new int[x , y];
        
        Queue<Tuple<int, int>> ol = new Queue<Tuple<int, int>>();
        
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {                     
                if (mountain[i][j] != '^')
                    continue;

                board[i,j] = 1;

                bool isOl = false;
                for (int d = 0; d < 4; d++)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx < 0 || nx >= x ||
                        ny < 0 || ny >= y)
                    {
                        isOl = true;
                        break;
                    }

                    if (mountain[nx][ny] == ' ')
                    {
                        isOl = true;
                        break;
                    }
                }

                if (isOl)
                {
                    ol.Enqueue(Tuple.Create(i, j));
                    board[i, j] = 2;
                }
            }
        } 

        while (ol.Count != 0)
        {
            var p = ol.Dequeue();
            ans = Math.Max(ans, board[p.Item1, p.Item2]);
            for (int d = 0; d < 4; d++)
            {
                int nx = p.Item1 + dx[d];
                int ny = p.Item2 + dy[d];

                if (nx < 0 || nx >= x ||
                    ny < 0 || ny >= y)
                    continue;

                if (board[nx, ny] != 1)
                    continue;

                board[nx, ny] = board[p.Item1, p.Item2] + 1;
                ol.Enqueue(Tuple.Create(nx, ny)); 
            }
        } 

        return ans - 1;
    }
}