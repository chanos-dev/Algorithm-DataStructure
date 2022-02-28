using System;

public class Persist 
{
	public static int Persistence(long n) 
	{
		int or = (int)n;
    int cnt = 0;
    while (or >= 10)
    {
        int temp = or;
        or = 1;
        while(temp != 0)
        {
            or *= temp % 10;
            temp /= 10;
        }
        cnt++;
    }

    return cnt;
	}
}