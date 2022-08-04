public class Fibonacci
{
    public static int Fib(int n)
    {
        if (n <= 2)
            return 1;
        // your code here!
        return Fib(n - 1) + Fib(n - 2);
    }
}