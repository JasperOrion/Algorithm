/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
        }
        //*若为99999类似的情况，扩容数组0，改第一位为1
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
// @lc code=end
