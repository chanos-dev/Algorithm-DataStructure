public class Number
{
    public int DigitalRoot(long n)
    {
        do
        {
            int temp = 0;
            while (n != 0)
            {
                temp += (int)(n % 10);
                n /= 10;
            }

            n = temp;
        } while (n > 10);

        return (int)n;
    }
}