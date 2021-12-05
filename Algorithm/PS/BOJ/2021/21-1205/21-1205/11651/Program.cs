using System;
using System.Collections.Generic;
using System.Text;

class _11651
{
    public struct Point : IComparable<Point>
    {
        public int x;
        public int y;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public int CompareTo(Point other)
        {
            if (this.y == other.y)
                return x.CompareTo(other.x);

            return y.CompareTo(other.y);
        }

        public override string ToString()
        {
            return $"{x} {y}";
        }
    }

    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<Point> points = new List<Point>(100000);

        for (int i = 0; i < n; i++)
        {
            string[] items = Console.ReadLine().Split(' ');

            points.Add(new Point(int.Parse(items[0]), int.Parse(items[1])));
        }

        points.Sort();

        StringBuilder sb = new StringBuilder();

        foreach (var point in points)
        {
            sb.AppendLine(point.ToString());
        }

        Console.WriteLine(sb);
    }
}