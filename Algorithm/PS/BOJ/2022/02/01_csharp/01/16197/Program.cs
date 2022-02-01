using System;

namespace _16197
{
    class Program
    {
        private static int n;
        private static int m;
        private static int ans = 9999999;

        private static int[] dx = new[] { 1, 0, -1, 0 };
        private static int[] dy = new[] { 0, 1, 0, -1 };

        private static Point[] Pos = new Point[2];

        private static char[,] board = new char[21, 21];
        static void Main(string[] args)
        {
            var inputItems = Console.ReadLine().Split(' ');

            n = int.Parse(inputItems[0]);
            m = int.Parse(inputItems[1]);

            int idx = 0;
            for (int i=0; i<n; i++)
            {
                var line = Console.ReadLine();
                for(int j=0; j<line.Length; j++)
                {
                    board[i, j] = line[j];
                    if (board[i, j] == 'o')
                        Pos[idx++] = (new Point(i, j));
                }
            }

            Solution();

            if (ans > 10)
                Console.Write("-1");
            else
                Console.Write(ans);
        }

        private static void Solution()
        {
            for(int d=0; d<4; d++)
            {
                Move(Pos, d, 1);
            }
        }

        private static void Move(Point[] pos, int d, int k)
        {
            if (k > 10)
                return;
            if (k > ans)
                return;

            Point[] temp = new Point[2];

            for(int i=0; i<temp.Length; i++)
            {
                temp[i] = new Point(pos[i].X + dx[d], pos[i].Y + dy[d]);
            } 

            if (CheckDroppedBall(temp) == 2)
                return;
            else if (CheckDroppedBall(temp) == 1)
            {
                if (ans > k)
                    ans = k;
                return;
            }

            for (int i = 0; i < temp.Length; i++)
            {
                if (board[temp[i].X, temp[i].Y] == '#')
                    temp[i] = pos[i];
            }

            bool isSamePos = false;
            for (int i = 0; i < temp.Length - 1; i++)
            {
                if (temp[i].Equals(temp[i + 1]))
                    isSamePos = true;
            }

            if (isSamePos)
                return;

            for (int m=0; m<4; m++)
            {
                Move(temp, m, k + 1);
            }
        }

        private static int CheckDroppedBall(Point[] pos)
        {
            int o = 0;

            foreach(var p in pos)
            {
                if (p.X < 0 || p.X >= n || p.Y < 0 || p.Y >= m)
                    o++;
            }

            return o;
        }
    }

    struct Point
    {
        public int X;
        public int Y;

        public Point(int x, int y)
        {
            this.X = x;
            this.Y = y;
        }
    }
}