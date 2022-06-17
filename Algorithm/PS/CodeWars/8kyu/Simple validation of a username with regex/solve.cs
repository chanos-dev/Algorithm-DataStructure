using System;
using System.Text.RegularExpressions;
using System.Linq;

public class Kata
{
    public static bool ValidateUsr(string username)
    {
        if (string.IsNullOrEmpty(username)) return false;
        if (username.Length < 4 || username.Length > 16) return false;
        if (username.Any(c => c == ' ' || char.IsUpper(c))) return false;

        return true;
    }
}