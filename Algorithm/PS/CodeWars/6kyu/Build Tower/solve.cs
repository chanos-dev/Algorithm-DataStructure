public class Kata
{
    public static string[] TowerBuilder(int nFloors)
    {
        string[] ans = new string[nFloors];

        for (int i = 0; i < nFloors; i++)
        {
            int s = nFloors * 2 - 1;
            char[] l = new char[s];
            for (int j = 0; j < s; j++)
            {
                if (j <= (nFloors - 1) + i && j >= (nFloors - 1) - i) l[j] = '*';
                else l[j] = ' ';
            }
            ans[i] = new string(l);
        }
        return ans;
    }
}