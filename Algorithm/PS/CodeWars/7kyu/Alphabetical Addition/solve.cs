using System;

public class Kata
{
    public static char AddLetters(char[] letters)
    {
        if (letters.Length == 0) return 'z';

        int c = letters.Length - 1;
        for (int i = 0; i < letters.Length; i++)
            c += (int)(letters[i] - 'a');

        return (char)(c % 26 + 'a');
    }
}