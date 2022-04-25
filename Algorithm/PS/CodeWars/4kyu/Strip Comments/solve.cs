using System.Text;
using System.Linq; 
public class StripCommentsSolution
{
    public static string StripComments(string text, string[] commentSymbols)
    {
        bool isStop = false; 

        StringBuilder sb = new StringBuilder();
        foreach(char c in text)
        {
            if (commentSymbols.Contains(c.ToString()))
            {
                isStop = true;
            }
            else if (c == '\n')
            {
                isStop = false;
                if (sb.Length > 0 && sb[sb.Length - 1] == ' ') sb = sb.Remove(sb.Length - 1, 1);
                sb.Append(c);
            } 
            else
            {
                if (isStop) continue; 
                sb.Append(c); 
            }
        }

        if (sb.ToString().Trim() == "") return string.Empty;
        if (sb.Length > 0 && sb[sb.Length - 1] == ' ') sb = sb.Remove(sb.Length - 1, 1);
        return sb.ToString();
    }
}