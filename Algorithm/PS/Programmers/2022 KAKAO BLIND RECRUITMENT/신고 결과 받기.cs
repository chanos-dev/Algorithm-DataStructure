using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int[] solution(string[] id_list, string[] report, int k)
    {
        var users = new Dictionary<string, int>();
        var reported = new Dictionary<string, Dictionary<string, bool>>();

        foreach (var id in id_list)
        {
            users.Add(id, 0);
            reported.Add(id, new Dictionary<string, bool>());
        }

        foreach (var re in report)
        {
            var items = re.Split(' ');

            var id = items[0];
            var target = items[1];

            if (reported[id].ContainsKey(target))
                continue;

            reported[id][target] = true;
            users[target]++;
        }

        var ans = new int[id_list.Length];
        foreach (var u in users)
        {
            if (u.Value < k)
                continue;

            foreach (var ru in reported.Keys)
            {
                if (!reported[ru].ContainsKey(u.Key))
                    continue;

                var idx = Array.IndexOf(id_list, ru);
                ans[idx]++;
            }
        }

        return ans;
    }
}