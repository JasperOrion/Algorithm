#include <iostream>
using namespace std;
int aa(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}
int main()
{
    int arr[5][5];
    int count = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                count += aa(i, 2);
                count += aa(j, 2);
            }
        }
    cout << count;
    return 0;
}
