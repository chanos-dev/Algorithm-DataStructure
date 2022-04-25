using System;
using System.Collections.Generic;

public class DirReduction
{
    public static string[] dirReduc(String[] arr)
    {
        Stack<string> stk = new Stack<string>();

        foreach(var direction in arr)
        {
            if (stk.Count != 0)
            {
                if (stk.Peek() == "NORTH" &&
                    direction == "SOUTH")
                    stk.Pop();
                else if (stk.Peek() == "SOUTH" &&
                    direction == "NORTH")
                    stk.Pop();
                else if (stk.Peek() == "EAST" &&
                    direction == "WEST")
                    stk.Pop();
                else if (stk.Peek() == "WEST" &&
                    direction == "EAST")
                    stk.Pop();
                else stk.Push(direction);
            }
            else stk.Push(direction);
        }

        string[] directions = new string[stk.Count];
        int idx = stk.Count - 1;
        while (stk.Count != 0)
        {
            directions[idx--] = stk.Pop();
        }

        return directions;
    }
}