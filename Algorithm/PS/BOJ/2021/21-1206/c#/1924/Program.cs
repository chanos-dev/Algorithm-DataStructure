using System;
using System.Linq;

class _1924
{
    static void Main()
    {
        var xy = Console.ReadLine().Split(' ');

        int add = GetAddDays(xy[0]);

        switch((int.Parse(xy[1]) + add) % 7)
        {
            case 0:
                Console.WriteLine("SUN");
                break;
            case 1:
                Console.WriteLine("MON");
                break;
            case 2:
                Console.WriteLine("TUE");
                break;
            case 3:
                Console.WriteLine("WED");
                break;
            case 4:
                Console.WriteLine("THU");
                break;
            case 5:
                Console.WriteLine("FRI");
                break;
            case 6:
                Console.WriteLine("SAT");
                break;
        }
    }

    private static int GetAddDays(string v)
    {
        var d = int.Parse(v);
        int add = 0;

        var to = new[]
        {
            1, 3, 5, 7, 8, 10, 12,
        };

        var tt = new[]
        {
            4, 6, 9, 11,
        };

        for(int i=1; i<d; i++)
        {
            if (to.Contains(i))
                add += 3;
            else if (tt.Contains(i))
                add += 2;
        }

        return add;
    }
}