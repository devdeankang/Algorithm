using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy07
{
    // 가장 큰 수
    // https://school.programmers.co.kr/learn/courses/30/lessons/84512

    class VowelDictionary
    {
        public List<int> GetIndexPattern()
        {
            List<int> _indexPatterns = new List<int>();
            _indexPatterns.Add(1);

            for (int i =1; i<5; i++)
            {
                _indexPatterns.Add(_indexPatterns[i - 1] * 5 + 1);
            }

            return _indexPatterns;
        }

        public int solution(string word)
        {
            string strPattern = "AEIOU";            
            int answer = 0;

            List<int> indexPatternList = GetIndexPattern();
            indexPatternList.Reverse();

            for(int i =0; i<word.Length; i++ )
            {
                int wordIndex = strPattern.IndexOf(word[i]);
                answer += wordIndex * indexPatternList[i] + 1;
            }

            return answer;            
        }
    }
}