using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy07
{

    // 가장 큰 수
    // https://school.programmers.co.kr/learn/courses/30/lessons/42746

    class TheGreatestNumber
    {        
        public string solution(int[] numbers)
        {            
            int numLength = numbers.Length;
            List<string> strList = new List<string>();
            bool isAllZero = true;
            StringBuilder sb = new StringBuilder();
            foreach(int num in numbers)
            {
                // 0 Check
                if (num != 0)
                    isAllZero = false;

                strList.Add(num.ToString());
            }
            if (isAllZero == true) return "0";

            strList.Sort((element1, element2) => (element2 + element1).CompareTo(element1 + element2));

            foreach (string str in strList)
                sb.Append(str);

            return sb.ToString();
        }
    }
}