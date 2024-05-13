using System.Collections.Generic;

public class AddMore
{
    public static List<int> AddExtra(List<int> listOfNumbers)
    {
        List<int> ans = new List<int>(listOfNumbers)
        {
            1,
        };

        return ans;
    }
}