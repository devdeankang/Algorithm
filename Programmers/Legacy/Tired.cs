using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy09
{
    class Tired
    {
        // 피로도
       // https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=csharp


        public int answer = 0;
        public bool[] visit;

        public int solution(int k, int[,] dungeons)
        {
            visit = new bool[dungeons.GetLength(0)];
            for (int i = 0; i < visit.Length; i++) visit[i] = false;

            Recursion(k, dungeons, visit, 0);
            return answer;
        }

        public int Recursion(int k, int[,] dungeons, bool[] visit, int count)
        {
            for (int i = 0; i < dungeons.GetLength(0); i++)
            {
                if (k >= dungeons[i, 0] && visit[i] == false )
                {
                    visit[i] = true;
                    Recursion(k - dungeons[i, 1], dungeons, visit, count + 1);
                    visit[i] = false;
                }
            }
            answer = Math.Max(count, answer);
            return answer;
        }

    }
}
