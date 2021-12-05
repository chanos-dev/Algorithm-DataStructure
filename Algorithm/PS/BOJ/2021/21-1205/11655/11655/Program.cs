using System;

class _111655
{
    static void Main()
    {
        string str = Console.ReadLine();

        foreach (var s in str)
        {
            if ((s >= 'a' && s <= 'z') ||
                (s >= 'A' && s <= 'Z'))
            { 
                if (s < 91)
                {
                    var p = s + 13;

                    if (p > 90)
                        Console.Write((char)(65 + (p - 91)));
                    else
                        Console.Write((char)(p));
                }
                else
                {
                    var p = s + 13;

                    if (p > 122)
                        Console.Write((char)(97 + (p - 123)));
                    else
                        Console.Write((char)(p));
                }


            }
            else
            {
                Console.Write(s);
            }
        }
    }
}