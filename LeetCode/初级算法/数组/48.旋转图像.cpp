/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int half = n / 2;
        int temp;

        for (int i = 0; i < half; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
// @lc code=end
