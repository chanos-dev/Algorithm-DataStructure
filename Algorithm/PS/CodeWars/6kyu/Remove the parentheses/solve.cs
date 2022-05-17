using System;
using System.Text;
using System.Collections.Generic;

namespace Solution
{
    public static class Kata
    {
        public static string RemoveParentheses(string s)
        {
            Stack<char> parentheses = new Stack<char>();
            StringBuilder sb = new StringBuilder();

            foreach (char c in s)
            {
                if (c == '(') parentheses.Push(c);
                if (parentheses.Count > 0)
                {
                    if (c == ')') parentheses.Pop();
                    continue;
                }
                sb.Append(c);
            }
            return sb.ToString();
        }
    }
}