using System.Collections.Generic;

public class SnailSolution
{
   public static int[] Snail(int[][] array)
   {
      int i = 0;
      int j = -1;

      int o = 1;
      int idx = array.Length;

      List<int> ans = new List<int>();
      while(ans.Count != (array.Length * array[0].Length))
      {
          for(int lj=0; lj<idx; lj++)
          {
              j += o;
              ans.Add(array[i][j]);
          }

          idx--;

          for(int li=0; li<idx; li++)
          {
              i += o;
              ans.Add(array[i][j]);
          }

          o *= -1;
      }

      return ans.ToArray();
   }
}