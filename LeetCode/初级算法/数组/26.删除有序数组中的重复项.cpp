/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (nums[left] == nums[right])
            {
                right++;
            }
            else
            {
                left++;
                nums[left] = nums[right];
            }
        }
        return ++left;
    }
};
// @lc code=end
