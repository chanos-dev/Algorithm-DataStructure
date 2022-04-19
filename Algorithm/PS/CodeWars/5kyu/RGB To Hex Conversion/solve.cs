public static class Kata
{
    public static string Rgb(int r, int g, int b)
    {
        if (r > 255) r = 255;
        if (g > 255) g = 255;
        if (b > 255) b = 255;

        string sr = ConvertToHex(r).PadLeft(2, '0');
        string sg = ConvertToHex(g).PadLeft(2, '0');
        string sb = ConvertToHex(b).PadLeft(2, '0');

        return $"{sr}{sg}{sb}";
    }

    private static string ConvertToHex(int v)
    {
        if (v <= 0) return string.Empty;
        return ConvertToHex(v / 16) + Hex(v % 16);
    }

    private static string Hex(int v)
    {
        switch(v)
        {
            case 10: return "A";
            case 11: return "B";
            case 12: return "C";
            case 13: return "D";
            case 14: return "E";
            case 15: return "F";
            default:
                return $"{v}";
        }
    }
}