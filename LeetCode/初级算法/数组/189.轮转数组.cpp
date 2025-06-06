/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    // void rotate(vector<int> &nums, int k)
    // {
    //     //*法一:   反转数组
    //     //*注意范围是否越界
    //     int n = nums.size();
    //     if (n == 0)
    //         return;
    //     k %= n; //*确保k的长度不要超过数组长度n。
    //     change(nums, 0, n - 1);
    //     change(nums, 0, k - 1);
    //     change(nums, k, n - 1);
    // }
    // void change(vector<int> &arr, int start, int end)
    // {
    //     while (start < end)
    //     {
    //         int temp = arr[start];
    //         arr[start++] = arr[end];
    //         arr[end--] = temp;
    //     }
    // }
    // void rotate(vector<int> &nums, int k)
    // { //*使用临时数组暂时存储
    //     //*注意范围是否越界
    //     int n = nums.size();
    //     if (n == 0)
    //         return;
    //     k %= n; //*确保k的长度不要超过数组长度n。
    //     vector<int> tempArr(n);
    //     for (int i = 0; i < n; i++)
    //         tempArr[i] = nums[i];
    //     for (int i = 0; i < n; i++)
    //         nums[(i + k) % n] = tempArr[i];
    // }
    void rotate(vector<int> &nums, int k)
    {
        /*从第一个下标flag开始,向右移动(flag+k)%n个位置,(在这之前先将要改变位置的值存储下来),然后再将下标移动(flag+k)%n个位置,遍历一次,当n%k==0时,会出现死循环,生成数组记录是否修改过对应位置,若已经访问过一次,让flag+1
         */
        //*注意范围是否越界
        int n = nums.size();
        if (n == 0)
            return;
        k %= n; //*确保k的长度不要超过数组长度n。
        int flag = 0;
        vector<bool> isGet(n);
        int temp0 = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (isGet[flag] == true)
            {
                flag = (flag + 1) % n;
                i--;
                temp0 = nums[flag];
            }
            else
            {
                isGet[flag] = true; // 不能忘了
                int temp = nums[(flag + k) % n];
                nums[(flag + k) % n] = temp0;
                flag = (flag + k) % n;
                temp0 = temp;
            }
        }
    }
};
// @lc code=end
