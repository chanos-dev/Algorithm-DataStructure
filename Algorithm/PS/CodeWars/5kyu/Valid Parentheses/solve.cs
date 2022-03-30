using System.Collections.Generic;

public class Parentheses
{
    public static bool ValidParentheses(string input)
    {
        Stack<char> stk = new Stack<char>(); 

        foreach (char c in input)
        {
            if (c == '(') stk.Push(c);
            else if (c == ')')
            {
                if (stk.Count == 0) return false;
                stk.Pop();
            }
        }

        if (stk.Count != 0) return false;

        return true;
    }
}