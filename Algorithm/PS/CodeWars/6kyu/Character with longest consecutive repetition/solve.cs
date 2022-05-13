namespace Solution
{
    using System;
    using System.Linq;

    public static class Kata
    {
        public static Tuple<char?, int> LongestRepetition(string input)
        {
            if (string.IsNullOrEmpty(input))
                return Tuple.Create<char?, int>(null, 0);

            int maxCnt = 0;
            char maxC = ' ';

            int curCnt = 0;
            char cur = ' ';

            foreach (var c in input)
            {
                if (cur == c) curCnt++;
                else
                {
                    curCnt = 1;
                    cur = c;
                }

                if (maxCnt < curCnt)
                {
                    maxCnt = curCnt;
                    maxC = c;
                }
            }

            return Tuple.Create<char?, int>(maxC, maxCnt);
        }
    }
}