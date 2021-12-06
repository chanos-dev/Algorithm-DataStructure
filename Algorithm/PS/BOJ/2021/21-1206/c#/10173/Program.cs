using System;
using System.Collections.Generic;
using System.Text;

class _10173
{
    static void Main()
    {
        StringBuilder sb = new StringBuilder();

        while(true)
        {
            var s = Console.ReadLine();
            if (s == "EOI")
                break;

            if (s.ToLower().Contains("nemo"))
                sb.AppendLine("Found");
            else
                sb.AppendLine("Missing");
        }

        Console.WriteLine(sb);
    }
}