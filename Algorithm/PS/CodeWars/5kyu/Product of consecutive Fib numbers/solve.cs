using System.Collections.Generic;

public class ProdFib
{
    public static ulong[] productFib(ulong prod)
    { 
        List<ulong> fibo = new List<ulong>()
        {
            0,
            1,
            1,            
        };

        while(true)
        { 
            if (fibo[fibo.Count - 2] * fibo[fibo.Count - 1] == prod)
            {
                return new ulong[]
                {
                    fibo[fibo.Count - 2],
                    fibo[fibo.Count - 1],
                    1
                };
            }
            else if (fibo[fibo.Count - 2] * fibo[fibo.Count - 1] > prod)
            {
                return new ulong[]
                {
                    fibo[fibo.Count - 2],
                    fibo[fibo.Count - 1],
                    0,
                };
            }
          
            fibo.Add(fibo[fibo.Count - 2] + fibo[fibo.Count - 1]);
        } 
    }
}