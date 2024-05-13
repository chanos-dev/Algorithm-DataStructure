using System.Linq;

namespace Solution
{
    public static class Program
    {
        public static string RepeatStr(int n, string s)
        {
            return string.Join("", Enumerable.Repeat(s, n));
        }
    }
}