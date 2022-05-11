using System.Linq;

public class Kata
{
    public static string StringClean(string s)
    {
        return string.Join("", s.Where(v => !char.IsDigit(v)));
    }
}