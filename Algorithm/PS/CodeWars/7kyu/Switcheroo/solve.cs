public class Kata
{
    public static string Switcheroo(string x)
    {
        string ans = string.Empty;
        foreach (char c in x)
        {
            if (c == 'a') ans += "b";
            else if (c == 'b') ans += "a";
            else ans += "c";
        }
        return ans;
    }
}