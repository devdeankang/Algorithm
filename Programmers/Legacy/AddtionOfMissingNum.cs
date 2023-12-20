using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy02
{
    // 없는 숫자 더하기
    // https://programmers.co.kr/learn/courses/30/lessons/86051

    public class AddtionOfMissingNum
    {
        public int solution(int[] numbers)
        {
            int answer = 0;
            int sumOfNumbers = 0;

            foreach (int num in numbers) sumOfNumbers += num;
            for (int num = 0; num <= 9; num++) answer += num;
            
            return answer -= sumOfNumbers;
        }
    }
}
