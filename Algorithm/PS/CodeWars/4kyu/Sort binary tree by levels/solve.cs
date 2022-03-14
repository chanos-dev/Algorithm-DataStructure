using System;
using System.Collections.Generic;

class Kata
{
  public static List<int> TreeByLevels(Node node)
  {
      List<int> ans = new List<int>();

      if (node is null)
          return ans;

      Queue<Node> q = new Queue<Node>();
      q.Enqueue(node);

      while(q.Count != 0)
      {
          Node n = q.Dequeue();
          ans.Add(n.Value);

          if (n.Left != null)
              q.Enqueue(n.Left);
          if (n.Right != null)
              q.Enqueue(n.Right);
      }

      return ans;
  } 
}