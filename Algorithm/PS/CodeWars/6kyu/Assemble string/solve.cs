using System.Text;

public class Kata
{
    public static string Assemble(string[] copies)
    {
        if (copies.Length == 0) return string.Empty;

        int len = copies[0].Length;
        StringBuilder sb = new StringBuilder();

        for(int idx=0; idx<len; idx++)
        {
            char v = '*';

            for (int c=0; c<copies.Length; c++)
            {
                if (copies[c].Length <= idx) continue;                
                if (copies[c][idx] == '*') continue;
                v = copies[c][idx];
                break;
            } 

            if (v == '*') sb.Append("#");
            else sb.Append(v);
        }

        return sb.ToString();
    }
}