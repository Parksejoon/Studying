using System;
using System.Collections.Generic;

class ChessMetric
{
    int[] dx = new int[] { 1, 1, 1, 0, -1, -1, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2 };
    int[] dy = new int[] { 1, 0, -1, -1, -1, 0, 1, 1, -1, -2, -2, -1, 1, 2, 2, 1 };
    long[,,] dp = new long[100, 100, 55];

    public long howMany(int size, int[] start, int[] end, int numMoves)
    {
        int sx = start[0], sy = start[1];
        int ex = end[0], ey = end[1];

        dp[sy, sx, 0] = 1;
        
        for (int i = 1; i <= numMoves; i++)
        {
            for (int x = 0; x < size; x++)
            {
                for (int y = 0; y < size; y++)
                {
                    for (int j = 0; j < 16; j++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx < 0 || nx >= size || ny < 0 || ny >= size)
                        {
                            continue;
                        }

                        dp[ny, nx, i] += dp[y, x, i - 1];
                    }
                }
            }
        }

        return dp[ey, ex, numMoves];
    }
}
