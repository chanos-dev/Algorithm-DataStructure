public class Kata
{
    public static string High(string s)
    {
        string ans = string.Empty;
        int ansC = -1;

        string cur = string.Empty;
        int curC = 0;

        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] != ' ')
            {
                curC += s[i] - 'a' + 1;
                cur += s[i];
            }

            if (s[i] == ' ' || (s.Length - 1) == i)
            {
                if (ansC < curC)
                {
                    ans = cur;
                    ansC = curC;
                }

                cur = string.Empty;
                curC = 0;
            }
        }
        return ans;
    }
}