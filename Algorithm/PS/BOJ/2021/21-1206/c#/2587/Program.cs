using System;
using System.Collections.Generic;
using System.Text;

class _2587
{
    static void Main()
    {
        StringBuilder sb = new StringBuilder();  

        for(int i=0; i<5; i++)
        {
            var s = Console.ReadLine();

            if (s.Contains("FBI"))
            {
                sb.Append($"{i + 1} ");
            }
        }

        if (sb.Length > 0)
            Console.WriteLine(sb);
        else
            Console.WriteLine("HE GOT AWAY!");
    }
}