using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy08
{

// Search Insert Position
// https://leetcode.com/problems/search-insert-position/submissions/

    class SearchInsertPosition
    {
        public int SearchInsert(int[] nums, int target)
        {
            List<int> numList = nums.ToList();

            if (!numList.Contains(target))
            {
                numList.Add(target);
                numList.Sort();
            }

            for (int i = 0; i < numList.Count; i++)
            {
                if (numList[i] == target)
                {
                    return i;
                }
            }

            return 0;
        }
    }
}
