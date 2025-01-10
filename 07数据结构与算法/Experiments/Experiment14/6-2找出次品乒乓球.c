int FindPingpang(double p[], int m)
{
    double base = p[0] >= p[1] ? p[0] : p[1];
    for (int i = 0; i < m; i++)
    {
        if (p[i] != base)
        {
            return i;
        }
    }
}