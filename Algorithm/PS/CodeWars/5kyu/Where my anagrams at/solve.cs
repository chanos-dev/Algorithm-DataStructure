using System;
using System.Collections.Generic;

public static class Kata
{
    public static List<string> Anagrams(string word, List<string> words)
    {
        List<string> anagramList = new List<string>();

        foreach(var w in words)
        {
            if (w.Length != word.Length) continue;

            bool[] finded = new bool[word.Length];
            int findCnt = 0; 
            for(int idx=0; idx<word.Length;idx++)
            {
                for(int tidx=0; tidx<w.Length;tidx++)
                {
                    if (finded[tidx]) continue;

                    if (word[idx] == w[tidx])
                    {
                        finded[tidx] = true;
                        findCnt++;
                        break;
                    }
                }  
            }

            if (findCnt == word.Length)
                anagramList.Add(w);
        }

        return anagramList;
    }
}