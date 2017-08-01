using System;
using System.Collections.Generic;

public class CrazyBot
{
    bool[,] field = new bool[100, 100];
    double[] prob = new double[4];
    int[] vx = new int[] { 1, -1, 0, 0 };
    int[] vy = new int[] { 0, 0, 1, -1 };

    public double getProbability(int n, int east, int west, int south, int north)
    {
        prob[0] = east / 100.0;
        prob[1] = west / 100.0;
        prob[2] = south / 100.0;
        prob[3] = north / 100.0;

        return dfs(50, 50, n);
    }

    double dfs(int x, int y, int n)
    {
        if (field[x, y]) return 0;
        if (n == 0) return 1;

        double ret = 0;

        field[x, y] = true;
        for (int i = 0; i < 4; i++)
        {
            ret += dfs(x + vx[i], y + vy[i], n - 1) * prob[i];
        }
        field[x, y] = false;

        return ret;
    }
}
