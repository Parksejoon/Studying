using System;
using System.Collections.Generic;

class FriendScore
{
    public int highestScore(string[] Friends)
    {
        int ans = 0;
        int n = Friends[0].Length;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;

            for (int j = 0; j < n; j++)             //모든 친구관계를 확인
            {
                if (i == j) continue;               //자기자신은 건너뛰고

                if (Friends[i][j] == 'Y')           //직접친구인경우 카운트 추가
                {
                    cnt++;
                }
                else
                {
                    for (int k = 0; k < n; k++)     //간접친구탐색
                    {
                        if (Friends[i][k] == Friends[k][j] && Friends[i][k] == 'Y')
                        {
                            cnt++;
                            break;
                        }
                    }
                }

            }

            ans = Math.Max(ans, cnt);
        }

        return ans;
    }
}
