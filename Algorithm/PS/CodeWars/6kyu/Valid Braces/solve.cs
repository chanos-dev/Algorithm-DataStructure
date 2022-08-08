using System;
using System.Linq;
using System.Collections.Generic;

public class Brace
{

    public static bool validBraces(String braces)
    {
        Stack<char> stk = new Stack<char>();

        foreach (char b in braces)
        {
            if (b == '(' || b == '{' || b == '[')
                stk.Push(b);
            else
            {
                if (stk.Count == 0)
                    return false;

                if (Math.Abs(stk.Peek() - b) > 2)
                    return false;

                stk.Pop();
            }
        }

        return stk.Count == 0;
    }
}