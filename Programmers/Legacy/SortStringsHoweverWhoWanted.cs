using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy
{
    class SortStringsHoweverWhoWanted
    {
        // 문자열 내 마음대로 정렬하기
        // https://programmers.co.kr/learn/courses/30/lessons/12915

        public static string[] solution(string[] strings, int n)
        {
            List<string> sortedStrings = new List<string>(strings.Length);
            List<string> answer = new List<string>(strings.Length);

            for(int i = 0; i<strings.Length; i++)
            {
                sortedStrings.Add(string.Concat(strings[i][n], strings[i]));
            }
            sortedStrings.Sort();

            foreach(string str in sortedStrings)
            {                
                answer.Add(str.Substring(1));
            }            

            return answer.ToArray();
        }
    }
}
