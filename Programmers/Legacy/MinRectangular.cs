using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlogorithmStudy03
{
    // 최소직사각형
    // https://programmers.co.kr/learn/courses/30/lessons/86491

    class MinRectangular
    {
        public int solution(int[,] sizes)
        {            
            int maxValue = -1;
            int maxPair = 0;

            foreach (int size in sizes)
            {
                if (maxValue < size) maxValue = size;
            }

            for (int i = 0; i<sizes.GetLength(0); i++)
            {
                int temp = 0;

                for (int j =0; j<sizes.GetLength(1); j ++)
                {
                    if (temp == 0)
                    {
                        temp = sizes[i, j];
                        continue;
                    }

                    if (temp > sizes[i, j] && sizes[i, j] > maxPair)
                        maxPair = sizes[i, j];
                    else if (temp <= sizes[i, j] && temp > maxPair)
                        maxPair = temp;
                }
            }

            return maxValue * maxPair;
        }
    }
}
