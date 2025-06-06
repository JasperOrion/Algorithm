#include <iostream>
using namespace std;
int main()
{
    int n, x = 0;
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        bool flag = false;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '+' && s[i + 1] == '+')
            {
                flag = true;
                break;
            }
        }
        if (flag)
            x++;
        else
            x--;
        n--;
    }
    cout << x;
    return 0;
}