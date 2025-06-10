//*从 1−n 这 n 个整数中随机选取任意多个，每种方案里的数从小到大排列，按字典序输出所有可能的选择方案。
/*样例输入 3
  样例输出
  1
  1 2
  1 2 3
  1 3
  2
  2 3
  3
*/
//*递归求解
#include <iostream>
using namespace std;

int arr[10];

void Print_one_result(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i)
            cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return;
}

void f(int i, int j, int n)
{
    if (j > n)
        return;
    for (int k = j; k <= n; k++)
    {
        arr[i] = k;
        Print_one_result(i);
        f(i + 1, k + 1, n);
    }
}

int main()
{
    int n;
    cin >> n;
    f(0, 1, n);
    return 0;
}