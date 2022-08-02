public class Kata
{
    public static bool Solution(string str, string ending)
    {
        if (str.Length < ending.Length)
            return false;
        int ec = ending.Length;

        for (int idx = str.Length - ec; idx < str.Length; idx++)
            if (str[idx] != ending[idx + ec - str.Length])
                return false;

        return true;
    }
}