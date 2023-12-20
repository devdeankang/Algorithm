using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy
{
    // 모의고사
    // https://programmers.co.kr/learn/courses/30/lessons/42840

    class MockExam
    {
        public List<int[]> solvingPatterns = new List<int[]>(3);
        public int[] studentReports = new int[3];

        private void InitSolvingPatterns()
        {
            solvingPatterns.Add(new int[5] { 1, 2, 3, 4, 5 });
            solvingPatterns.Add(new int[8] { 2, 1, 2, 3, 2, 4, 2, 5 });
            solvingPatterns.Add(new int[10] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 });
        }

        private void SetStudentAnswers(int[] answers)
        {
            for (int i = 0; i < answers.Length; i++)
            {
                if (answers[i] == solvingPatterns[0][i % 5]) studentReports[0]++;
                if (answers[i] == solvingPatterns[1][i % 8]) studentReports[1]++;
                if (answers[i] == solvingPatterns[2][i % 10]) studentReports[2]++;
            }

        }

        public int[] solution(int[] answers)
        {
            List<int> rankTable = new List<int>(3);

            InitSolvingPatterns();
            SetStudentAnswers(answers);

            for (int i = 0; i < studentReports.Length; i++)
            {
                if (studentReports[i] == studentReports.Max())
                    rankTable.Add(i + 1);
            }

            return rankTable.ToArray();
        }
    }
}
