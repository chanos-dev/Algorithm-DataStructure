using System.Linq;

public class Xbonacci
{
    public double[] Tribonacci(double[] signature, int n)
    {
        if (n == 0)
            return new double[0];

        if (n < 3)
            return signature.Take(n).ToArray();

        double[] ans = new double[n];

        ans[0] = signature[0];
        ans[1] = signature[1];
        ans[2] = signature[2];

        for (int i = 3; i < n; i++)
            ans[i] = ans[i - 3] + ans[i - 2] + ans[i - 1];

        return ans;
    }
}