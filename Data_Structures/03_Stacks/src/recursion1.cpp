#include <iostream>
using namespace std;
int fbi(int i)
{
    if (i < 2)
        return i == 0 ? 0 : 1;
    else
    {
        return fbi(i - 1) + fbi(i - 2);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << "显示斐波那契数列" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << fbi(i) << " ";
    }
}