/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> arr;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p0 = 0, p1 = 0;
        while (p0 < nums1.size() && p1 < nums2.size())
        {
            if (nums1[p0] == nums2[p1])
            {
                // 只添加不重复的元素
                if (arr.empty() || arr.back() != nums1[p0])
                    arr.push_back(nums1[p0]);
                p0++;
                p1++;
            }
            else if (nums1[p0] < nums2[p1])
                p0++;
            else
                p1++;
        }
        return arr;
    }
};
// @lc code=end
