using System.Linq;

public static class Kata
{
    public static string Likes(string[] name)
    {
        switch (name.Length)
        {
            case 0:
                return "no one likes this";
            case 1:
                return $"{name[0]} likes this";
            case 2:
                return $"{string.Join(" and ", name)} like this";
            case 3:
                return $"{string.Join(" and ", string.Join(", ", name.Take(2)), name[2])} like this";
            default:
                return $"{string.Join(", ", name.Take(2))} and {name.Length-2} others like this";
        }
    }
}