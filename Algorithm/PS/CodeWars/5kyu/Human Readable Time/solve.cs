public static class TimeFormat
{
    public static string GetReadableTime(int seconds)
    {
        int s = seconds % 60;
        int m = seconds / 60 % 60;
        int h = seconds / 3600;

        return $"{h:D2}:{m:D2}:{s:D2}";
    }
}