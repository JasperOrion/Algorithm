/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0;
        int count = nums.size();
        for (int right = 0; right < count; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                ++left;
            }
        }
        return left;
    }
};
// @lc code=end
