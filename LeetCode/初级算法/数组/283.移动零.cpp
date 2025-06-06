/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        /*思路：快慢双指针；快指针不为0时把值赋给慢指针
        并把指针都往右移动一位 ，为0时快指针往右移动一位
        循环一次后慢指针前面的数为原数组顺序，再循环一次将慢指针到数组结束的区间赋0
        */
        int first = 0;
        int second = 0;
        while (second < nums.size())
        {
            if (nums[second] != 0)
                nums[first++] = nums[second++];
            else
                second++;
        }
        while (first < nums.size())
            nums[first++] = 0;
    }
};
// @lc code=end
