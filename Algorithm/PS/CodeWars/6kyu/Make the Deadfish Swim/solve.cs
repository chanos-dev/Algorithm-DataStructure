using System.Collections.Generic;
public class Deadfish
{
    public static int[] Parse(string data)
    {
        List<int> ans = new List<int>();
        int val = 0;
        foreach (var c in data)
        {
            switch (c)
            {
                case 'i':
                    val++;
                    break;
                case 'd':
                    val--;
                    break;
                case 's':
                    val *= val;
                    break;
                case 'o':
                    ans.Add(val);
                    break;
            }
        }
        return ans.ToArray();
    }
}