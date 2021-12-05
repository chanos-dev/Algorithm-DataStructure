using System;
using System.Linq;

class _11170
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        for (int i = 0; i < n; i++)
        {
            var v = Console.ReadLine().Split(' ').Select(c => int.Parse(c)).ToArray();

            int cnt = 0;

            for (int j=v[0]; j<=v[1]; j++)
            {
                cnt += j.ToString().Count(c => c == '0');
            }

            Console.WriteLine(cnt);
        }
    }
}