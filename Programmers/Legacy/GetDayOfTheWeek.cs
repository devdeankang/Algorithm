using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy
{
    class GetDayOfTheWeek
    {
        // 2016년
        // https://programmers.co.kr/learn/courses/30/lessons/12901

        public string solution(int a, int b)
        {
            string[] week = new string[7] { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
            int dayCnt = 0;

            if (a == 1) return week[b % 7 != 0 ? b % 7 - 1 : 6];

            for (a -= 1; a > 0; a--)
            {
                dayCnt += GetMonthToDay(a);
            }

            return week[(dayCnt + b) % 7 != 0 ? (dayCnt + b) % 7 - 1 : 6];
        }

        private int GetMonthToDay(int a)
        {
            int monthToDay = 0;

            switch (a)
            {
                case 2:
                    monthToDay = 29;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    monthToDay = 30;
                    break;
                default:
                    monthToDay = 31;
                    break;
            }

            return monthToDay;
        }
    }
}
