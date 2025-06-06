/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        //*先排序，重复的数必相邻
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size() - 1; i++)
        // {
        //     if (nums[i] == nums[i + 1])
        //     {
        //         return true;
        //     }
        // }
        // return false;
        //*直接用集合，加入集合时，返回false时有重复项
        // set<int> s;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (!s.insert(nums[i]).second)
        //         return true;
        // }
        // return false;
    }
};
// @lc code=end
