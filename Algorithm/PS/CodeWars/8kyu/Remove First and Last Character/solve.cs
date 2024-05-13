public class Kata
{
    public static string Remove_char(string s)
    {
        return s.Remove(0, 1).Remove(s.Length - 2, 1);
    }
}