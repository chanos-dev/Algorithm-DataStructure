public class Kata
{
    public static string FakeBin(string x)
    {
        string ans = string.Empty;
        foreach (char c in x)
            ans += c >= '5' ? "1" : "0";
        return ans;
    }
}