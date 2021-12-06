using System;
using System.Collections.Generic;
using System.Text;

class _5598
{
    static void Main()
    {
        var s = Console.ReadLine();

        foreach(char c in s)
        {
            int g = c - 3;

            if (g < 65)
                g += 26;

            Console.Write((char)g);
        }
    }
}