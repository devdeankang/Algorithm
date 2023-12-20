using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy05
{
    // 조이스틱
    // https://programmers.co.kr/learn/courses/30/lessons/42860

    class JoyStick
    {
        Dictionary<char, int> charIndexDic = new Dictionary<char, int>();

        public void InitCharIndex()
        {
            for (int i = 0; i < 13; i++)
            {
                charIndexDic[(char)('A' + (char)i)] = i;
            }

            for (int i = 13; i < 26; i++)
            {
                charIndexDic[(char)('A' + (char)i)] = 26 - i;
            }
        }

        public int GetKeyMovementCount(string name)
        {
            int count = 0;
            int moveCount = name.Length-1;

            for (int i = 0; i<name.Length; i++)
            {
                moveCount = GetKeyPassedCount(name, i, moveCount);                
                if (name[i] == 'A') continue;
                count += charIndexDic[name[i]];
            }

            return count + moveCount;
        }

        public int GetKeyPassedCount(string name, int index, int moveCount)
        {            
            int nextIndex = index + 1;
            while (nextIndex < name.Length && name[nextIndex] == 'A') nextIndex++;
            moveCount = Math.Min(moveCount, index + name.Length - nextIndex + Math.Min(index, name.Length - nextIndex));
            return moveCount;
        }

        public int solution(string name)
        {                       
            InitCharIndex();            
            return GetKeyMovementCount(name);
        }
    }
}
