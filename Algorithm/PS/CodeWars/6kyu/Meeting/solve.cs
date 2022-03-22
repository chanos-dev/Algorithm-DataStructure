using System.Collections.Generic;
using System.Linq;
using System.Text;

public class JohnMeeting
{
    public static string Meeting(string s)
    {
        Dictionary<string, List<string>> kv = new Dictionary<string, List<string>>();
        string k = "", v = "";
        string temp = "";
        s += ";";
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == ':')
            {
                k = temp;
                temp = "";
            }
            else if (s[i] == ';')
            {
                v = temp;
                temp = "";

                k = k.ToUpper();
                v = v.ToUpper();
                if (!kv.ContainsKey(v))
                    kv[v] = new List<string>();

                kv[v].Add(k);
            }
            else temp += s[i].ToString();
        }

        StringBuilder sb = new StringBuilder();

        foreach (var key in kv.Keys.OrderBy(key => key).ToArray())
        {
            sb.Append(string.Join("", kv[key].OrderBy(val => val).ToArray().Select(val => $"({key}, {val})").ToArray()));
        }

        return sb.ToString();
    }
}