using System;

class _10820
{
    static void Main()
    {
        while(true)
        {
            string s = Console.ReadLine();
            if (string.IsNullOrEmpty(s)) break;

            int a = 0;
            int A = 0;
            int b = 0;
            int n = 0;

            foreach (char c in s)
            {
                if (c == ' ')
                    b++;
                else if (c >= 'a' && c <= 'z')
                    a++;
                else if (c >= 'A' && c <= 'Z')
                    A++;
                else if (c >= '0' && c <= '9')
                    n++;
            }

            Console.WriteLine($"{a} {A} {n} {b}");
        }
    } 
}