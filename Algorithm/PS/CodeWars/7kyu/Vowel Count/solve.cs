public static class Kata
{
    public static int GetVowelCount(string str)
    {
        int vowelCount = 0;

        foreach(char c in str)
        {
            if (c == 'a' ||
                c == 'e' ||
                c == 'i' ||
                c == 'o' ||
                c == 'u')
                vowelCount++;
        }

        return vowelCount;
    }
}