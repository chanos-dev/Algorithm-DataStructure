using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int[] solution(int[] fees, string[] records)
    {
        int defaultMinitues = fees[0];
        int defaultCost = fees[1];
        int unitMinitues = fees[2];
        int unitCost = fees[3];

        Dictionary<string, int> parking = new Dictionary<string, int>();
        Dictionary<string, bool> parkingFlag = new Dictionary<string, bool>();
        Dictionary<string, int> parkingTime = new Dictionary<string, int>();

        foreach (var record in records)
        {
            var items = record.Split(' ');
            var time = items[0].Split(':');
            var hour = int.Parse(time[0]);
            var minute = int.Parse(time[1]);
            var car = items[1];
            var flag = items[2];

            var totalMinutes = (int)new TimeSpan(hour, minute, 0).TotalMinutes;

            if (flag == "IN")
            {
                parking[car] = totalMinutes;
                parkingFlag[car] = true;

                if (!parkingTime.ContainsKey(car))
                    parkingTime[car] = 0;
            }
            else
            {
                parkingTime[car] += totalMinutes - parking[car];
                parkingFlag[car] = false;
            }
        }

        // check left
        foreach (var flag in parkingFlag)
        {
            if (!flag.Value) continue;

            var totalMinutes = (int)new TimeSpan(23, 59, 0).TotalMinutes;
            parkingTime[flag.Key] += totalMinutes - parking[flag.Key];
        }

        Dictionary<string, int> pay = new Dictionary<string, int>();
        foreach (var time in parkingTime)
        {
            pay[time.Key] = defaultCost;

            if (time.Value > defaultMinitues)
            {
                var leftTime = (int)Math.Ceiling((time.Value - defaultMinitues) / (double)unitMinitues);
                pay[time.Key] += (leftTime * unitCost);
            }
        }

        return pay.OrderBy(kv => kv.Key).Select(kv => kv.Value).ToArray();
    }
}