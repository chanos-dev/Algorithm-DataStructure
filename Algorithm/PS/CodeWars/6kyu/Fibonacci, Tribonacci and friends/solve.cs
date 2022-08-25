using System.Linq;
public class Xbonacci
{
    public double[] xbonacci(double[] signature, int n)
    {
        int f = signature.Length;

        if (n <= f)
            return signature.Take(n).ToArray();

        double[] ans = new double[n];

        for (int i = 0; i < signature.Length; i++)
            ans[i] = signature[i];

        for (int i = f; i < n; i++)
        {
            double s = 0;
            for (int j = i - f; j <= i; j++)
                s += ans[j];
            ans[i] = s;
        }

        return ans;
    }
}