using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Dinglemouse
{
    public static string FireAndFury(string tweet)
    {
        char[] word = new char[4];
        int idx = 0;
        string fury = "FURY";
        string fire = "FIRE";
        Queue<string> q = new Queue<string>();

        foreach (char c in tweet)
        {
            if (c != 'E' && c != 'F' && c != 'I' && c != 'R' && c != 'U' && c != 'Y')
                return "Fake tweet.";

            if (c == 'F')
                idx = 0;

            word[idx++] = c;

            if (idx == 4)
            {
                idx = 0;

                bool find = true;
                for (int i = 0; i < 4; i++)
                {
                    if (word[i] != fury[i])
                    {
                        find = false;
                        break;
                    }
                }
                if (find) q.Enqueue(fury);
                find = true;
                for (int i = 0; i < 4; i++)
                {
                    if (word[i] != fire[i])
                    {
                        find = false;
                        break;
                    }
                }
                if (find) q.Enqueue(fire);
            }
        }

        string ans = string.Empty;
        int count = 0;
        while (q.Count != 0)
        {
            string t = q.Dequeue();
            if (q.Count == 0 || t != q.Peek())
            {
                string add = string.Empty;
                // "I am really furious."
                if (t == fury)
                {
                    for (int i = 0; i < count; i++)
                        add += "really ";

                    ans += $"I am {add}furious. ";
                }
                // "You and you are fired!"
                else
                {
                    for (int i = 0; i < count; i++)
                        add += "and you ";

                    ans += $"You {add}are fired! ";
                }
                count = 0;
            }
            else count++;
        }

        if (string.IsNullOrEmpty(ans)) 
            return "Fake tweet.";

        return ans.Trim();
    }
}