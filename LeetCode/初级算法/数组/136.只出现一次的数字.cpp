/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        //*直接做异或运算
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            num = num ^ nums[i];
        }
        return num;
    }
};
// @lc code=end
