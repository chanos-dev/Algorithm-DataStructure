public class Kata
{
    public static bool Check(object[] a, object x)
    {
        foreach (var c in a)
        {
            if (object.Equals(c, x))
                return true;
        }
        return false;
    }
}