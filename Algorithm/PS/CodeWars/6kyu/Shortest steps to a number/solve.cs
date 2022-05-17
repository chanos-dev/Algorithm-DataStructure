using System;
using System.Collections.Generic;
namespace Solution
{
    public static class Kata
    {
        public static int ShortestStepsToNum(int num)
        {
            bool[] vist = new bool[10005];
            Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
            queue.Enqueue(new Tuple<int, int>(1, 0));

            while (queue.Count > 0)
            {
                Tuple<int, int> t = queue.Dequeue();
                if (t.Item1 == num)
                    return t.Item2;

                if (t.Item1 < 0 || t.Item1 > 10000) continue;
                if (vist[t.Item1]) continue;
                vist[t.Item1] = true;

                queue.Enqueue(Tuple.Create(t.Item1 + 1, t.Item2 + 1));
                queue.Enqueue(Tuple.Create(t.Item1 * 2, t.Item2 + 1));
            }

            return 0;
        }
    }
}