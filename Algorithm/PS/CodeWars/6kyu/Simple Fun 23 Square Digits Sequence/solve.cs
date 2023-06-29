namespace myjinxin
{
    using System;
    
    public class Kata
    {
        public int SquareDigitsSequence(int a0)
        {
            int seq = 1;
            int[] numbers = new int[651];
            numbers[a0]++;

            while (numbers[a0] < 2)
            {
                a0 = TransferDigits(a0);
                numbers[a0]++;
                seq++;
            }

            return seq;
        }

        private int TransferDigits(int a)
        {
            int sum = 0;

            while(a > 0)
            {
                sum += (int)Math.Pow(a % 10, 2);
                a /= 10;
            } 

            return sum;
        }
    }
}