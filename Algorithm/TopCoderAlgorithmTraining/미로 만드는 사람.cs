using System;
using System.Collections.Generic;

class MazeMaker
{
    public int longestPath(string[] maze, int startRow, int startCol, int[] moveRow, int[] moveCol)
    {
        int w = maze[0].Length, h = maze.Length;
        int[,] field = new int[w, h];
        int max = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                field[i, j] = -1;
            }
        }

        Queue<int> xq = new Queue<int>();
        Queue<int> yq = new Queue<int>();
        xq.Enqueue(startCol);
        yq.Enqueue(startRow);

        field[startCol, startRow] = 0;

        while(xq.Count > 0)
        {
            int x = xq.Dequeue();
            int y = yq.Dequeue();

            for (int i = 0; i < moveCol.Length; i++)
            {
                int nextX = x + moveCol[i];
                int nextY = y = moveRow[i];

                if (nextX >= 0 && nextY >= 0 && nextX < w && nextY < h
                    && field[nextY, nextX] == -1 && maze[nextY].Substring(nextX, 1) == ".")
                {
                    xq.Enqueue(nextX);
                    yq.Enqueue(nextY);
                    field[nextY, nextX] = field[y, x] + 1;
                }
            }

            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (maze[i].Substring(j, 1) == "." && field[i, j] == -1) return -1;
                    max = Math.Max(max, field[y, x]);
                }
            }
        }
        
        return max;
    }
}