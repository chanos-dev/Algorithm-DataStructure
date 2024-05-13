public class Kata
{
    public static int UniTotal(string str)
    {
        return str.Sum(c => (int)c);
    }
}