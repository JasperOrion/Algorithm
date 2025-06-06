/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

//*法一:
//*双层循环，时间复杂度为O(n^2),不好😒
// int slow = 0;
// int fast;
// while (slow < nums.size())
// {
//     fast = slow + 1;
//     while (fast < nums.size())
//     {
//         if (nums[fast] == (target - nums[slow]))
//             return {slow, fast};
//         else
//             fast++;
//     }
//     slow++;
// }
// return {};
//*这样也可以
// int i = 0;
//  int j = 1;
//  int t;
//  for (i = 0; i < nums.size(); i++)
//  {
//      t = target - nums[i];
//      for (j = i + 1; j < nums.size(); j++)
//      {
//          if (t == nums[j])
//          {
//              return {i, j};
//          }
//      }
//  }
//  return {};
// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //
    }
};
// @lc code=end
