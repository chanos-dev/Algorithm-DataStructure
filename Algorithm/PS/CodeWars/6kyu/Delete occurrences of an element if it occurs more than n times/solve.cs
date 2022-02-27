using System;
using System.Collections.Generic;
using System.Linq;

public class Kata {
  public static int[] DeleteNth(int[] arr, int x) 
  {  
    int[] c = new int[arr.Max()+1];
    List<int> l = new List<int>(arr.Length);

    for(int i=0; i<arr.Length; i++)
    {
        if (c[arr[i]] >= x) continue;
        l.Add(arr[i]);
        c[arr[i]]++;                
    }

    return l.ToArray();
  }
}