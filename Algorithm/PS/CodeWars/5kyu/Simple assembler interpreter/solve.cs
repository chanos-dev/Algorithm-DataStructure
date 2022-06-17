using System;
using System.Linq;
using System.Collections.Generic;

namespace Solution
{
    public static class SimpleAssembler
    {
        public static Dictionary<string, int> Interpret(string[] program)
        {
            var ans = new Dictionary<string, int>();
            int pos = 0;
            while (pos < program.Length)
            {
                var cmds = program[pos++].Split(' ');

                switch (cmds[0])
                {
                    case "mov":
                        int v;

                        if (ans.ContainsKey(cmds[2]))
                            v = ans[cmds[2]];
                        else
                            v = int.Parse(cmds[2]);

                        if (ans.ContainsKey(cmds[1]))
                            ans[cmds[1]] = v;
                        else
                            ans.Add(cmds[1], v);
                        break;
                    case "inc":
                        ans[cmds[1]]++;
                        break;
                    case "dec":
                        ans[cmds[1]]--;
                        break;
                    case "jnz":
                        int jv;
                        if (ans.ContainsKey(cmds[1]))
                            jv = ans[cmds[1]];
                        else
                            jv = int.Parse(cmds[1]);

                        if (jv != 0)
                        {
                            pos--;
                            pos += int.Parse(cmds[2]);
                        }
                        break;
                }
            }

            return ans;
        }
    }
}