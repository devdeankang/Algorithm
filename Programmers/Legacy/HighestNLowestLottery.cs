using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlogorithmStudy03
{
    // 로또의 최고 순위와 최저순위
    // https://programmers.co.kr/learn/courses/30/lessons/77484

    class HighestNLowestLottery
    {
        public int GetLotteryRank(int answerCnt)
        {
            if (7 - answerCnt >= 6)
                return 6;
            else
                return (7 - answerCnt);
        }

        public int[] solution(int[] lottos, int[] win_nums)
        {
            int[] answer = new int[2];
            int zeroCnt = 0;
            int equalCnt = 0;

            foreach(int selectedNum in lottos) 
            {
                if (selectedNum == 0)
                {
                    zeroCnt++;
                    continue;
                }

                foreach(int winNum in win_nums)
                {
                    if (selectedNum == winNum) equalCnt++;
                }
            }

            answer[0] = GetLotteryRank(equalCnt + zeroCnt);
            answer[1] = GetLotteryRank(equalCnt);
            
            return answer;
        }

    }
}
