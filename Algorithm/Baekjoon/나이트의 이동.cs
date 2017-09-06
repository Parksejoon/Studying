using System;
using System.Collections.Generic;

class MainApp
{
    public static void Main()
    {
        int tc = int.Parse(Console.ReadLine());

        for (int t = 0; t < tc; t++)
        {
            int size = int.Parse(Console.ReadLine());
            int[,] field = new int[size, size];   //필드
            

            string inP = Console.ReadLine();
            string[] InP = inP.Split();

            int sx = int.Parse(InP[0]);      //시작점 X
            int sy = int.Parse(InP[1]);      //시작점 Y


            string inP2 = Console.ReadLine();
            string[] InP2 = inP2.Split();

            int ex = int.Parse(InP2[0]);      //끝점 X
            int ey = int.Parse(InP2[1]);      //끝점 Y

            int[] moveX = { 1, 2, -1, -2 };
            int[] moveY = { 2, 1, 2, 1 };

            Queue<int> xq = new Queue<int>();
            Queue<int> yq = new Queue<int>();
            Queue<int> cn = new Queue<int>();

            int cnt = 0;
            int nowX = sx;
            int nowY = sy;

            field[nowX, nowY] = 1;

            while (nowX != ex || nowY != ey)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (nowX + moveX[i] >= 0 && nowX + moveX[i] < size
                        && nowY + moveY[i] >= 0 && nowY + moveY[i] < size
                        && field[nowX + moveX[i], nowY + moveY[i]] != 1)
                    {
                        xq.Enqueue(nowX + moveX[i]);
                        yq.Enqueue(nowY + moveY[i]);
                        cn.Enqueue(cnt + 1);
                        field[nowX + moveX[i], nowY + moveY[i]] = 1;
                    }
                }

                for (int i = 0; i < 4; i++)
                {
                    if (nowX - moveX[i] >= 0 && nowX - moveX[i] < size
                        && nowY - moveY[i] >= 0 && nowY - moveY[i] < size
                        && field[nowX - moveX[i], nowY - moveY[i]] != 1)
                    {
                        xq.Enqueue(nowX - moveX[i]);
                        yq.Enqueue(nowY - moveY[i]);
                        cn.Enqueue(cnt + 1);
                        field[nowX - moveX[i], nowY - moveY[i]] = 1;
                    }
                }

                nowX = xq.Dequeue();
                nowY = yq.Dequeue();
                cnt = cn.Dequeue();
            }

            Console.WriteLine(cnt);
        }
    }
}
