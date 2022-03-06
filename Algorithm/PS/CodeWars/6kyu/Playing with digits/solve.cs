using System;
using System.Collections.Generic;

public class DigPow {
    public static long digPow(int n, int p) 
    {
        Stack<int> stk = new Stack<int>();

        int temp = n;
        while(temp != 0)
        {
            stk.Push(temp % 10);
            temp /= 10;
        }

        int sum = 0;
        while(stk.Count != 0)
        {
            int top = stk.Pop();
            sum += (int)Math.Pow(top, p++);
        }

        int ans = -1;

        for(int k=1; n * k <= sum; k++)
        {
            if (n * k == sum)
            {
                ans = k;
                break;
            }
        }

        return ans;
	}
}