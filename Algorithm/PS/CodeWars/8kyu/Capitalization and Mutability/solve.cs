public class Kata
{
    public static string CapitalizeWord(string word)
    {
        string ans = ((char)(word[0] - 32)).ToString();
        for (int i = 1; i < word.Length; i++)
            ans += word[i];

        return ans;
    }
}