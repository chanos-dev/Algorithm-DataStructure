using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _14267
{
    class Program
    {
        private static int[] Person = new int[100001];
        private static List<int>[] ScorePerson = new List<int>[100001];

        private static void Init(int n)
        {
            for(int i=0; i<n+1; i++)
                ScorePerson[i] = new List<int>();
        }

        private static void Set(string[] person)
        {
            for(int i=0; i<person.Length; i++)
            {
                if (person[i] == "-1") continue;
                ScorePerson[int.Parse(person[i])].Add(i+1);
            }
        }

        static void Main(string[] args)
        {
            int n, m;

            var input = Console.ReadLine().Split(' ');

            n = int.Parse(input[0]);
            m = int.Parse(input[1]);

            Init(n);

            var person = Console.ReadLine().Split(' ');
            Set(person);

            for (int i=0; i<m; i++)
            {
                var w = Console.ReadLine().Split(' ');
                int p = int.Parse(w[0]);
                int k = int.Parse(w[1]);
                Person[p] += k;
            }

            Score(1);

            for(int i=1; i<=n; i++)
            {
                Console.Write($"{Person[i]} ");
            }
        }

        private static void Score(int s)
        {
            if (ScorePerson[s] is null) return;

            foreach(var i in ScorePerson[s])
            {
                Person[i] += Person[s];
                Score(i);
            }
        }
    }
}