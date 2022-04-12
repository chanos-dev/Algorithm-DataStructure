using System;

public partial class Node
{
    public int Data;
    public Node Next;

    public Node(int data)
    {
        this.Data = data;
        this.Next = null;
    }

    public static int Length(Node head)
    {            
        if (head is null)
            return 0;

        return 1 + Length(head.Next);
    }

    public static int Count(Node head, Predicate<int> func)
    {
        if (head is null)
            return 0;

        if (func.Invoke(head.Data))
            return 1 + Count(head.Next, func);
        else
            return Count(head.Next, func);
    }
}