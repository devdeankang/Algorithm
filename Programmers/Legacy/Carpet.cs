using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy05
{
    // 카페트
    // https://programmers.co.kr/learn/courses/30/lessons/42842


    class Carpet
    {
        public int[] solution(int brown, int yellow)
        {
            int[] answer = new int[2];
                        
            int width = 0;
            int height = 0;
                        
            for (int i = 1; i <= yellow; i++)
            {            
                if (yellow % i == 0)
                {
                    width = yellow / i;
                    height = i;

                    if (height <= width)
                    {
                        if ((width + 2) * (height + 2) == brown + yellow)
                        {
                            answer[0] = width + 2;
                            answer[1] = height + 2;                            
                            return answer;
                        }
                    }
                }
            }
            return answer;
        }
    }
}
